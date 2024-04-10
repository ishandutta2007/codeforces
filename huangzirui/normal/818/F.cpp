#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
int T;ll n;
inline ll calc(ll x){
	if(x>=n)return 0;
	ll res=x+min(x,(n-x)*(n-x-1)/2);
	//printf("%lld %lld\n",x,res);
	return res;
}
int main(){
	T=read();
	while(T--){
		scanf("%lld",&n);
		ll b=(1+2*n-(ll)sqrt(1+8*n))/2;
		//printf("%lld\n",b);
		ll ans=0;
		for(ll i=-5;i<=5;i++)
			ans=max(ans,calc(b+i));
		printf("%lld\n",ans);
	}
    return 0;
}