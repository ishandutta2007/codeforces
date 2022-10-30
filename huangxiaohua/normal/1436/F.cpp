#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t;
ll f[100500],a[100500];
ll ksm(ll a,ll p){
	ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;
}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

void get(int x){
	int i,j,k;
	ll s1,s2,num,tmp;
	s1=s2=num=tmp=0;
	for(i=x;i<=100000;i+=x){
		s1=su(s1,1ll*i*i%M*a[i]%M);
		s2=su(s2,i*a[i]%M);
		num+=a[i];
	}
	s2=su(s2*s2%M,M-s1);
	if(!num){return;}
	if(num>=2){tmp=su((num-2)%M*ksm(2,(M-1+num-3)%(M-1))%M,ksm(2,(M-1+num-2)%(M-1)));}
	f[x]=su(s2*tmp%M,(M+num-1)%M*s1%M*ksm(2,(M-1+num-2)%(M-1))%M);
	f[x]=su(f[x],M);
}

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		scanf("%d",&a[k]);
	}
	for(i=100000;i>=1;i--){
		get(i);
		for(j=i+i;j<=100000;j+=i){f[i]=su(f[i],M-f[j]);}
	}
	printf("%lld",f[1]);
}