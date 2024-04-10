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
const int N=300010;
int t,n,u,ans;
struct node{
	vector<int>a[N];
	int cnt;
	pii r[N];
	void reset(){
		for(rgi i=1;i<=n;++i)a[i].clear();
		cnt=0;
	}
	void getf(int v){read(u),a[u].pbk(v);}
	void dfs(int x){
		r[x].fi=++cnt;
		for(rgi to:a[x])dfs(to);
		r[x].se=++cnt;
	}
}X,Y;
set<pii>s;
int chkin(pii x,pii y){return x.fi>=y.fi&&x.se<=y.se;}
void dfs2(int x){
	auto in=s.lower_bound(Y.r[x]);
	pii tmp=pii(0,0);
	if(in!=s.begin()&&chkin(Y.r[x],*prev(in)))s.erase(tmp=*prev(in));
	if(in==s.end()||!chkin(*in,Y.r[x]))s.insert(Y.r[x]);
	ans=max(ans,(int)s.size());
	for(rgi to:X.a[x])dfs2(to);
	if(tmp.fi)s.insert(tmp);
	if(s.find(Y.r[x])!=s.end())s.erase(Y.r[x]);
}
signed main(){
	read(t);
	while(t--){
		read(n),X.reset(),Y.reset(),ans=0,s.clear();
		for(rgi i=2;i<=n;++i)X.getf(i);
		for(rgi i=2;i<=n;++i)Y.getf(i);
		Y.dfs(1),dfs2(1),write(ans,'\n');
	}
	return 0;
}