#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 998244353
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int T,n,i,ee,tot,a,c;ll ans;
struct node{int tp,c;}g[N];
inline bool cmp(node aa,node bb){
	if(aa.c==bb.c)return aa.tp<bb.tp;
	return aa.c<bb.c;
}
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a>>c,ans+=c,c+=a,g[++tot].tp=-1,g[tot].c=a,g[++tot].tp=1,g[tot].c=c;
	sort(g+1,g+tot+1,cmp);ee=-1;
	for(i=2;i<=tot;++i){
		if(g[i].tp<0&&ee==0)ans+=g[i].c-g[i-1].c;
		ee+=g[i].tp;
	}	cout<<ans;
	return 0;
}