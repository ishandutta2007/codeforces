#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

ll ksm(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*a%M;
		}p>>=1;a=a*a%M;
	}return res;
}
ll n,a,b,res,f[200500]={0,1,1};
int main(){
	for(int i=3;i<=200005;i++){
		f[i]=(f[i-2]+f[i-1])%M;
	}
	
	scanf("%lld",&n);
	a=ksm(2,M-2);
	res=f[n]*ksm(a,n)%M;
	printf("%lld",res);
}