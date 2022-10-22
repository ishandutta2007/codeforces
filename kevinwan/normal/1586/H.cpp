#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 2e5+10;
const int SIZE = 600;
const int BLOCKS = mn/SIZE+10;
const ll mod = 1e9+7;

vi g[mn],toll[mn];
int dep[mn],anc[mn][18],acc[mn][18];
void dfs(int x,int p){
	anc[x][0]=p;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i],t=toll[x][i];
		if(y==p)continue;
		dep[y]=dep[x]+1;
		acc[y][0]=t;
		dfs(y,x);
	}
}

int e[mn];
void go(int &res, int &a,int b){
	for(int i=0;b;i++,b>>=1)if(b&1){
		res=max(res,acc[a][i]);
		a=anc[a][i];
	}
}
int dist(int a,int b){
	int res = 0;
	if(dep[a]>dep[b])go(res,a,dep[a]-dep[b]);
	else go(res,b,dep[b]-dep[a]);
	for(int i=17;i>=0;i--){
		if(anc[a][i]!=anc[b][i]){
			res=max(res,max(acc[a][i],acc[b][i]));
			a=anc[a][i],b=anc[b][i];
		}
	}
	if(a!=b)res=max({res,acc[a][0],acc[b][0]});
	return res;
}
struct dsu{
	int p[mn],cost[mn];
	dsu(){iota(p,p+mn,0);}
	int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
	void mrg(int a,int b){
		a=f(a),b=f(b);
		if(a==b)return;
		if(e[a]<e[b])swap(a,b);
		p[b]=a;
		if(e[a]==e[b]){
			cost[a]=max({cost[a],cost[b],dist(a,b)});
		}
	}
} ds;
struct edge{
	int a,b,c,t;
};
struct query{
	int v,x,i;
};
int ans[mn][2];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>e[i];
	vector<edge> ve;
	for(int i=0;i<n-1;i++){
		int a,b,c,t;
		cin>>a>>b>>c>>t;
		ve.push_back({a,b,c,t});
		g[a].push_back(b);
		toll[a].push_back(t);
		g[b].push_back(a);
		toll[b].push_back(t);
	}
	dfs(1,1);
	for(int i=1;i<=17;i++)for(int j=1;j<=n;j++){
		anc[j][i]=anc[anc[j][i-1]][i-1];
		acc[j][i]=max(acc[j][i-1],acc[anc[j][i-1]][i-1]);
	}
	sort(ve.begin(),ve.end(),[](auto&a, auto&b){return a.c>b.c;});
	vector<query> vq;
	for(int i=0;i<q;i++){
		int v,x;
		cin>>v>>x;
		vq.push_back({v,x,i});
	}
	sort(vq.begin(),vq.end(),[](auto &a, auto&b){return a.v>b.v;});
	int cur=0;
	for(query&q:vq){
		while(cur<ve.size()&&ve[cur].c>=q.v){
			ds.mrg(ve[cur].a,ve[cur].b);
			cur++;
		}
		//cerr<<q.v<<" "<<cur<<endl;
		int y=ds.f(q.x);
		//cerr<<y<<endl;
		ans[q.i][0]=e[y];
		ans[q.i][1]=max(dist(q.x,y),ds.cost[y]);
	}
	for(int i=0;i<q;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}