#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define M 1000000007
int i,j,k,n,m,sb[75],z[75],tmp,a[25],res;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
int main(){
	for(i=2;i<=70;i++){
		if(!z[i]){
			tmp++;
			for(j=i+i;j<=70;j+=i){z[j]=1;}
			for(j=i;j<=70;j+=i){k=j;while((k%i)==0){k/=i;sb[j]^=b(tmp);}}
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);k=sb[k];
		for(j=19;j>=1;j--){
			if(k&b(j)){if(a[j]){k^=a[j];}else{a[j]=k;goto aaa;}}
			if(!k)break;
		}
		res++;aaa:;
	}
	printf("%lld",(ksm(2,res)-1+M)%M);
}