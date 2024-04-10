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
int n,k;
lint ans=0;

const lint mod=1000000007;
int mig[10];
int state[10],vis[10];

bool rec(int v){
	if(state[v]==1) return true;
	if(vis[v]) return false;
	vis[v]=1;
	if(!rec(mig[v])) return false;
	state[v]=1;
	return true;
}

bool judge(){
	REP(i,k) state[i]=-1,vis[i]=0;
	state[0]=1;

	REP(i,k) if(state[i]==-1){
		if(rec(i)==0) return false;
	}
	return true;
}

	
void dfs(int dep){
	if(dep==k){
		if(judge()) ++ans;
		return;
	}
	REP(i,k){
		mig[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	cin>>n>>k;

	dfs(1);

	ans=(ans*k)%mod;
	for(int i=k;i<n;++i) ans=(ans*(n-k))%mod;

	cout<<ans<<endl;


	return 0;
}