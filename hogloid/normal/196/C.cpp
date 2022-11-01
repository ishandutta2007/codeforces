#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<complex>
#include<map>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
typedef long long int lint;
static const lint INF =1e15; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef pair<int,int> pi;
vector<int> g[2000];
struct P{
	int x,y,id;
	P(){}
	P(int sx,int sy,int si){
		x=sx;y=sy;id=si;
	}
};
vector<P> p[2000];
P pos[2000];
int res[2000];
int n,m;
bool cmp_y(const P& a,const P& b){
	if(a.y==b.y) return a.x>b.x;
	return a.y<b.y;
}
int piv;
double ang[2000][2000];
bool cmp_ang(const P& a,const P& b){
	return ang[piv][a.id]<ang[piv][b.id];
}
int size[2000];
int prep(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		size[v]+=prep(to,v);
	}
	return size[v];
}
void dfs(int v,int par){
	int minid=min_element(p[v].begin(),p[v].end(),cmp_y)->id;
	res[minid]=v;
	piv=minid;
	sort(p[v].begin(),p[v].end(),cmp_ang);
	int cnt=0;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==par) continue;
		p[to].resize(size[to]);
		REP(j,size[to]){
			if(p[v][cnt].id==minid) ++cnt;
			p[to][j]=p[v][cnt++];
		}
		dfs(to,v);
	}
}
	
int main(){
	scanf("%d",&n);m=n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	p[0].resize(n);
	REP(i,n){
		cin>>p[0][i].x>>p[0][i].y;
		p[0][i].id=i;
	}
	REP(i,n) REP(j,n) if(i!=j){
		ang[i][j]=atan2((double)p[0][j].y-p[0][i].y,
			(double)p[0][j].x-p[0][i].x);
	}
	prep(0,-1);
	dfs(0,-1);
	REP(i,n) printf("%d%c",res[i]+1,i==n-1?'\n':' ');
	return 0;
}