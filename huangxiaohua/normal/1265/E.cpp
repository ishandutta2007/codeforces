#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

ll ksm(ll a,ll p){
	ll res=1;
	while(p){if(p&1){res=res*a%M;}p>>=1;a=a*a%M;}return res;
}

int i,j,n;
ll pre,k,tmp=1,inv100;

int main(){
	inv100=ksm(100,M-2);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&k);k=k*inv100%M;
		pre=(pre+tmp)%M;
		tmp=tmp*k%M;
	}
	printf("%lld",pre*ksm(tmp,M-2)%M);
}