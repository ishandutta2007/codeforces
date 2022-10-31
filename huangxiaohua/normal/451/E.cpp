#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define b(x) (1<<((x)-1))

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
int i,j,k,n,l,r;
ll a[25],inv=1,f[25],sum,res,m;

ll c(ll n,int m){
	if(n<m){return 0;}
	ll res=inv;
	for(;m;m--,n--){
		res=res*(n%M)%M;
	}
	return res;
}

int main(){
	scanf("%d%lld",&n,&m);
	for(i=1;i<n;i++){inv=inv*i%M;}
	inv=ksm(inv,M-2);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<b(n+1);i++){
		sum=0;
		for(j=1;j<=n;j++){
			if(i&b(j)){
				sum+=a[j]+1;
			}
		}
		f[__builtin_popcount(i)]+=c(m-sum+n-1,n-1);
	}
	res=f[0];
	for(i=1;i<=n;i++){
		res+=f[i]*((i&1)?-1:1);
	}
	printf("%lld",(res%M+M)%M);
}