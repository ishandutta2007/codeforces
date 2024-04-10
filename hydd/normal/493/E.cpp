#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,ans,res;
ll Ans[110000],p[110000],a,b,c;
void solve(int dep,ll a,ll x,ll b,ll y){//f(a)=x,f(b)=y
	if (!x||!y) return;
	if (x==y){
		p[dep]=x; ans=dep;
		for (int i=0;i<=dep;i++) Ans[i]=p[i];
		res++;
	}
	ll c=y%b; p[dep]=c;
	if (c%a!=x%a) return;
	solve(dep+1,a,(x-c)/a,b,(y-c)/b);
}
int main(){
//	freopen("polynomial.in","r",stdin);
//	freopen("polynomial.out","w",stdout);
//	scanf("%d",&T);
//	while (T--){
		scanf("%lld%lld%lld",&a,&b,&c);
		if (a==1&&b==1&&c==1){ puts("inf"); return 0;}
		if (a==b&&b!=c){ puts("0"); return 0;}
		res=0; solve(0,a,b,b,c); printf("%d\n",res);
//		if (res){
//			printf("%d",ans);
//			for (int i=ans;i>=0;i--) printf(" %lld",Ans[i]);
//			putchar('\n');
//		}
//	}
	return 0;
}