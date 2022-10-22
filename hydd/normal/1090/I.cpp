/*
	Time: 2020/12/20 21:30 - 21:42
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=5e18;//wrong: 1ll<<60
int T,n; ll l,r;//wrong: int
unsigned x,y,z,b[11000000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld%lld",&n,&l,&r);
		scanf("%u%u%u",&x,&y,&z);
		scanf("%u%u",&b[1],&b[2]);
		for (int i=3;i<=n;i++) b[i]=b[i-2]*x+b[i-1]*y+z;
		ll mn=INF,mx=-INF,tmp,ans=INF;
		for (int i=1;i<=n;i++){
			tmp=(ll)b[i]%(r-l+1)+l;
			if (mn<tmp) ans=min(ans,1ll*tmp*mn);
			else mn=tmp;
		}
		for (int i=n;i>=1;i--){
			tmp=(ll)b[i]%(r-l+1)+l;
			if (mx>tmp) ans=min(ans,1ll*tmp*mx);
			else mx=tmp;
		}
		if (ans==INF) puts("IMPOSSIBLE");
		else printf("%lld\n",ans);
	}
	return 0;
}