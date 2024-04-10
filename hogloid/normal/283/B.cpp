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
int a[200005];
pi mig[200005];

int flag[200005],vis[200005];
lint tot[200005];

bool dfs(int v){
	if(v==-1) return true;
	if(flag[v]!=-1) return flag[v];
	if(vis[v]) return false;
	vis[v]=1;
	if(dfs(mig[v].fr)){
		flag[v]=1;
		tot[v]=mig[v].sc+(mig[v].fr==-1?0:tot[mig[v].fr]);
		return true;
	}else{
		flag[v]=0;
		return false;
	}
}

int main(){
	scanf("%d",&n);
	REP(i,n-1) scanf("%d",&a[i+2]);

	REPN(i,n+1,2){
		int nxtX=i-a[i];
		if(nxtX<=0) mig[i]=mp(-1,a[i]);
		else{
			int prev=nxtX;
			nxtX+=a[nxtX];
			if(nxtX>n) mig[i]=mp(-1,a[i]+a[prev]);
			else mig[i]=mp(nxtX,a[i]+a[prev]);
		}
	}
	memset(flag,-1,sizeof(flag));
	
	flag[1]=0;

	for(int i=2;i<=n;++i) if(flag[i]==-1){
		dfs(i);
	}

	for(int i=1;i<=n-1;++i){
		int nxtX=1+i;
		if(flag[nxtX]==0) puts("-1");
		else{
			cout<<tot[nxtX]+i<<'\n';
		}
	}






	return 0;
}