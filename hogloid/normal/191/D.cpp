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
int belong[100005],cnt,id[100005];
vector<int> g[100005];
vector<int> group[100005];
int n,m;
vector<int> stk;
int vis[100005];
void dfs(int v,int p){
	vis[v]=1;
	stk.pb(v);
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		if(vis[to]){
			if(belong[to]!=-1) continue;
			int j=stk.size()-1;
			while(j>=0 && stk[j]!=to){
				belong[stk[j]]=cnt;
				--j;
			}
			belong[to]=cnt;
			++cnt;
			continue;
		}
		dfs(to,v);
	}
	stk.pop_back();
}

int rec(int v,int p){
	int be=belong[v],res=(group[be].size()>1);
	int exist=0;
	REP(i,group[be].size()){
		int v2=group[be][i];
		int ecnt=0;
		REP(j,g[v2].size()){
			int to=g[v2][j];
			if(belong[to]==be) continue;
			int tmp;
			if(to==p) tmp=1;
			else tmp=rec(to,v2);
			
			res+=tmp;
			++ecnt;
		}
		res-=ecnt/2;
		if(ecnt) ++exist;
	}
	if(exist>=2) --res;
	return res;
}




int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(belong,-1,sizeof(belong));

	dfs(0,-1);
	REP(i,n) if(belong[i]==-1) belong[i]=cnt++;
	
	REP(i,n) group[belong[i]].pb(i);
	printf("%d %d\n",rec(0,-1),m);	
		 
	return 0;
}