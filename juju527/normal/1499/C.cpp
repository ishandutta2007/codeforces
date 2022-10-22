#include<bits/stdc++.h>
using namespace std;
#define inf 1e16
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
int T,n,m,c[maxn];ll ans;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)
			c[i]=read();c[n+1]=mod;
		ans=inf;
		int mn1=mod,mn2=mod;
		ll sum1=0,sum2=0;		
		for(int i=1;i<=n;i+=2){
			mn1=min(mn1,c[i]);sum1+=c[i];
			if(i>1)ans=min(ans,sum1+sum2+1ll*mn1*(n-(i+1)/2)+1ll*mn2*(n-i/2));
			mn2=min(mn2,c[i+1]);sum2+=c[i+1];
			ans=min(ans,sum1+sum2+1ll*(mn1+mn2)*(n-(i+1)/2));
		}printf("%lld\n",ans);
	}
    return 0;
}//ni ke neng wa la