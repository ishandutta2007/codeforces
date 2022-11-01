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
struct uf{
	int par[105];
	void init(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u;
int deg[10];
vector<int> g[10][10];
vector<pi> ans;
int who;
bool check(int st=-1){
	u.init();
	REP(i,7){
		deg[i]=0;
		REP(j,7){
			deg[i]+=g[i][j].size();
			if(g[i][j].size()>0) u.unite(i,j);
		}
	}
	int p=-1;
	REP(i,7) if(deg[i]>0) p=i;
	int odd=0;who=p;
	REP(i,7){
		if(deg[i]>0 && u.root(i)!=u.root(p)) return false;
		if(deg[i]&1){
			++odd;
			who=i;
		}
	}
	if(st>=0 && p>=0 && u.root(p)!=u.root(st)) return false;
	if(odd>2) return false;
	return true;
}


int main(){
	scanf("%d",&n);
	int p;
	REP(i,n){
		int a,b;scanf("%d%d",&a,&b);
		g[a][b].pb(i+1);
		g[b][a].pb(-i-1);
	}

	if(!check()) puts("No solution");	
	else{
		int cur=who;
		while(n--){
			REP(i,7) if(g[cur][i].size()>0){
				int id=g[cur][i].back();
				g[cur][i].pop_back();
				g[i][cur].pop_back();
				if(check(i)){
					if(id>0) ans.pb(mp(id,1));
					else ans.pb(mp(-id,2));//inverse
					cur=i;
					goto exi;
				}
				g[i][cur].pb(-id);
				g[cur][i].pb(id);
			}
			exi:;
		}

		REP(i,ans.size()) printf("%d %c\n",ans[i].fr,ans[i].sc==2?'-':'+');
	}


	return 0;
}