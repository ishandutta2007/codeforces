#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=500010;
ll n,m,s[N],C,S[N];
struct node{
	ll w,siz,id;
}sh[N],g[N];
vector<node>v[N];
struct res{
	ll val,fr,f2,tr;
	bool operator<(res k)const{return val<k.val;}
	bool operator>(res k)const{return val>k.val;}
};
vector<res>dp[N][2];
#define sz(a,b) (int)(dp[a][b].size())
#define tp(a,b) dp[a][b][sz(a,b)-1]
void chg(ll &x){x=lower_bound(S+1,S+C+1,x)-S;}
vector<pii>gg;
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)read(sh[i].w,sh[i].siz),sh[i].id=i,S[++C]=sh[i].siz;
	read(m);
	for(rgi i=1;i<=m;++i)read(g[i].w,g[i].siz),g[i].siz++,g[i].id=i,S[++C]=g[i].siz,S[++C]=g[i].siz-1,S[++C]=g[i].siz+1;
	sort(S+1,S+C+1),C=unique(S+1,S+C+1)-S-1;
	for(rgi i=1;i<=n;++i)chg(sh[i].siz),s[sh[i].siz]=i;
	for(rgi i=1;i<=m;++i)chg(g[i].siz),v[g[i].siz].pbk(g[i]);
	dp[0][0].pbk(res{0,0,0,0});
	dp[0][1].pbk(res{0,0,0,0});
	for(rgi i=1;i<=C;++i){
		if(tp(i-1,1)>tp(i-1,0))dp[i][0].pbk(res{tp(i-1,1).val,1,sz(i-1,1)-1,0});
		else dp[i][0].pbk(res{tp(i-1,0).val,0,sz(i-1,0)-1,0});
		dp[i][1]=dp[i][0];
		if(sh[s[i]].w>sh[s[i-1]].w)sort(v[i].begin(),v[i].end(),[&](node x,node y){return x.w<y.w;});
		else sort(v[i].begin(),v[i].end(),[&](node x,node y){return x.w>y.w;});
		for(node k:v[i]){
			if(s[i]&&k.w>=sh[s[i]].w){
				res clc=res{tp(i,0).val+sh[s[i]].w,tp(i,0).fr,tp(i,0).f2,k.id};
				if(clc>tp(i,1))dp[i][1].pbk(clc);
			}
			if(s[i-1]&&k.w>=sh[s[i-1]].w){
				res clc=res{tp(i-1,0).val+sh[s[i-1]].w,tp(i-1,0).fr,tp(i-1,0).f2,k.id};
				if(clc>tp(i-1,1))dp[i-1][1].pbk(clc);
			}
			if(tp(i-1,1)>tp(i-1,0))dp[i][0].pbk(res{tp(i-1,1).val,1,sz(i-1,1)-1,0});
			else dp[i][0].pbk(res{tp(i-1,0).val,0,sz(i-1,0)-1,0});
		}
	}
	res ans=max(tp(C,0),tp(C,1));
	int now=C;
	write(ans.val,'\n');
	while(now){
		if(ans.tr)gg.pbk(pii(ans.tr,s[now]));
		ans=dp[--now][ans.fr][ans.f2];
	}
	write(gg.size(),'\n');
	for(pii k:gg)write(k.fi,' ',k.se,'\n');
	return 0;
}