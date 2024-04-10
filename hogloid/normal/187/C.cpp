#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n,m,k;
vector<int> g[100005];
queue<int> q;
int mark[100005],cost[100005],belong[100005];
pair<int,pi> edge[1000000];
struct uf{
	int par[100005];
	uf(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	bool unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return false;
		par[a]=b;
		return true;
	}
};
uf u;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,k) scanf("%d",&mark[i]),--mark[i];

	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int s,t;scanf("%d%d",&s,&t);--s;--t;
	mark[k++]=s;
	mark[k++]=t;
	memset(cost,-1,sizeof(cost));
	memset(belong,-1,sizeof(belong));
	REP(i,k) if(belong[mark[i]]==-1){
		belong[mark[i]]=mark[i];
		cost[mark[i]]=0;
		q.push(mark[i]);
	}
	int cnt=0;
	while(!q.empty()){
		int cur=q.front();q.pop();
		REP(i,g[cur].size()){
			int to=g[cur][i];
			if(cost[to]!=-1){
				if(belong[to]!=belong[cur]){
					edge[cnt++]=mp(cost[to]+cost[cur]+1,mp(belong[to],belong[cur]));
				}
				continue;
			}
			q.push(to);
			belong[to]=belong[cur];
			cost[to]=cost[cur]+1;
		}
	}
	sort(edge,edge+cnt);
	int res=-1;
	REP(i,cnt) if(u.unite(edge[i].sc.fr,edge[i].sc.sc)){
		if(u.root(s)==u.root(t)){
			res=edge[i].fr;
			break;
		}
	}
	printf("%d\n",res);

	return 0;
}