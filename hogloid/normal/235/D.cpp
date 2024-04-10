#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
vector<int> g[3005];
vector<int> cycle;
vector<int> back;
int vis[3005];
int iscycle[3005];
double inv[3005];
int dfs(int v,int p){
	back.pb(v);
	vis[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		if(vis[to]){
			while(!back.empty()){
				cycle.pb(back.back());
				back.pop_back();
				if(cycle.back()==to) break;
			}
			return 1;
		}
		if(dfs(to,v)){
			return 1;
		}
	}
	back.pop_back();
	return 0;
}
double ans=0;
void dfs2(int v,int p,int d=1){
	ans+=inv[d];
	REP(i,g[v].size()){
		int to=g[v][i];
		if((!iscycle[to] || !iscycle[v]) && to!=p) dfs2(to,v,d+1);
	}
}
void makepath(int v,int p,int d,vector<int>& ar){
	while(ar.size()<=d) ar.pb(0);
	ar[d]++;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(!iscycle[to] && to!=p) makepath(to,v,d+1,ar);
	}
}
vector<int> path[3005];	
int main(){
	cin>>n;
	REP(i,n){
		int a,b;scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1);
	REP(i,cycle.size()) iscycle[cycle[i]]=1;
	REPN(i,3005,1) inv[i]=1.0/i;
	REP(i,n){
		dfs2(i,-1);
	}
	int m=0;
	REP(i,n) if(iscycle[i]){
		makepath(i,-1,1,path[m++]);
	}
	int C=cycle.size();
	REP(i,m) REP(j,i){

		REP(k,path[i].size()) REP(l,path[j].size()){
			int elem=path[i][k]*path[j][l];
			if(!elem) continue;

			int dst1=k+l+i-j-1,dst2=k+l+C-(i-j)-1,
				dst3=k+l+C-2;

			ans+=(inv[dst1]+inv[dst2]-inv[dst3])*elem*2;
		}
	}
	printf("%.10f\n",ans);



	return 0;
}