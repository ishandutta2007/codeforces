#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
 
int n,m,j,t;
char sb[105000];
ll res,tmp,a[100500],b[100500],c[100500],i;
 
ll ksm(ll k,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*k%M;}
		k=k*k%M;p>>=1;
	}return res;
}
 
int main(){
	a[1]=b[1]=c[1]=1;
	for(i=2;i<=100000;i++){
		a[i]=a[i-1]*10%M;
		b[i]=a[i]*i%M;
		c[i]=b[i]+c[i-1];
		c[i]%=M;
		//printf("%lld\n",c[i]);
	}
	gets(sb+1);
	n=strlen(sb+1);
	for(i=1;i<=n;i++){
		tmp=sb[i]-'0';
		res+=tmp*(i%M*(i-1)%M*ksm(2,M-2)%M)*a[n-i+1]%M;
		res+=tmp*c[n-i]%M;
		res=(res%M)+M;res%=M;
		//printf("%lld %lld\n",tmp*(i%M*(i-1)%M*ksm(2,M-2)%M)*a[n-i+1]%M,c[n-i]);
	}
	printf("%lld\n",res);
}