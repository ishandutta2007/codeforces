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
bool g[305][305];
int flow[305][305];
int cap;
int n,m;

struct uf{
	int par[305];
	uf(){
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
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u;

int have[305],want[305];

int vis[305];

lint haveS[305],wantS[305];

pair<pi,int> ans[1000005];
int acnt;
int path[305],n2;
bool findpath(int s,int t){
	if(s==t){
		path[n2++]=t;
		return true;
	}
	vis[s]=1;
	REP(i,n) if(g[s][i] && !vis[i]){
		if(findpath(i,t)){
			path[n2++]=s;
			return true;
		}
	}
	return false;
};
void solve(int i,int j,int d){
	if(i==j) return;
	int t_=path[j-1],t=path[j];
	int delta=min(d,have[t_]);
	if(delta>0){
		ans[acnt++]=mp(mp(t_,t),delta);
		have[t]+=delta;
		have[t_]-=delta;
	}

	solve(i,j-1,d);

	int rest=d-delta;
	if(rest>0){
		ans[acnt++]=mp(mp(t_,t),rest);
		have[t]+=rest;
		have[t_]-=rest;
	}
}

int main(){
	cin>>n>>cap>>m;
	REP(i,n) scanf("%d",&have[i]);
	REP(i,n) scanf("%d",&want[i]);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a][b]=g[b][a]=1;
		u.unite(a,b);
	}
	REP(i,n) haveS[u.root(i)]+=have[i],wantS[u.root(i)]+=want[i];
	int fail=0;
	REP(i,n) if(haveS[i]!=wantS[i]) fail=1;
	if(fail){
		puts("NO");
		return 0;
	}
	
	bool changed=true;
	while(changed){
		changed=false;
		REP(i,n) if(have[i]!=want[i]){
			REP(j,n) if(have[j]!=want[j] && u.same(i,j) && 
					(have[i]<want[i])^(have[j]<want[j])){
				int s,t,d;
				if(have[i]<want[i]){
					t=i;
					s=j;
					d=min(want[i]-have[i],have[j]-want[j]);
				}else{
					t=j;
					s=i;
					d=min(have[i]-want[i],want[j]-have[j]);
				}
				memset(vis,0,sizeof(vis));
				n2=0;

				findpath(s,t);
				reverse(path,path+n2);
				
				solve(0,n2-1,d);
				changed=true;
				goto exi;
			}
		}
		exi:;
	}
	printf("%d\n",acnt);

	REP(i,acnt){
		printf("%d %d %d\n",ans[i].fr.fr+1,ans[i].fr.sc+1,ans[i].sc);
	}
			






	return 0;
}