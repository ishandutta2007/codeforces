#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
const int N=1e5+7,base=13131;
int n,m;
vector<int> g[N];
struct ask{int h,id;};
vector<ask> q[N];
int siz[N],dep[N];
void dfs_pre(int x){
	siz[x]=1;
	for(int y:g[x])dep[y]=dep[x]+1,dfs_pre(y),siz[x]+=siz[y];
}

typedef unsigned long long ull;
unordered_map<ull,int> p[N];
ull a[N];
const ull M=1e15+7;
int ans[N];
void add(int x){
	++p[dep[x]][a[x]];
	for(int y:g[x])add(y);
}
void del(int x){
	auto it=p[dep[x]].find(a[x]);
	it->second--;
	if(!it->second)p[dep[x]].erase(it);
	for(int y:g[x])del(y);
}
void dfs(int x){
	int son=0;
	for(int y:g[x])if(siz[y]>siz[son])son=y;
	for(int y:g[x])if(y!=son)dfs(y),del(y);
	if(son)dfs(son);
	for(int y:g[x])if(y!=son)add(y);
	for(auto t:q[x])ans[t.id]=dep[x]+t.h<=n?p[dep[x]+t.h].size():0;
	++p[dep[x]][a[x]];
}
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	REP(i,1,n){
		int x;cin>>s>>x;
		a[i]=0;
		for(auto j:s)a[i]=(a[i]*base+j)%M;
		g[x].push_back(i);
	}
	cin>>m;
	REP(i,1,m){
		int x,y;cin>>x>>y;
		q[x].push_back({y,i});
	}
	dfs_pre(0);siz[0]=0;dfs(0);
	REP(i,1,m)cout<<ans[i]<<endl;
	return 0;
}