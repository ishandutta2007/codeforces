#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
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
string s[2005];
int n,K;
int lcp[2005];
int prof[2005][2005];
struct uf{
	int par[2005];
	vector<int> dp[2005];
	void init(int n){
		REP(i,n){
			dp[i].resize(2);
		}
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b,int lb){
		a=root(a);b=root(b);
		vector<int> tmp(dp[a].size()+dp[b].size()-1);
		REP(i,dp[a].size()) REP(j,dp[b].size()) tmp[i+j]=max(tmp[i+j],dp[a][i]+dp[b][j]+lb*i*j);
		par[a]=b;
		dp[b]=tmp;
		dp[a].clear();
	}
};
uf u;
int used[2005];
int main(){
	
	scanf("%d%d",&n,&K);
	REP(i,n) cin>>s[i];
	sort(s,s+n);
	u.init(n);
	REP(i,n-1){
		int& t=lcp[i];
		for(t=0;t<s[i].size() &&t<s[i+1].size() && s[i][t]==s[i+1][t];++t);
	}
	REP(i,n-1){
		int tallest=-1,ind;
		REP(j,n-1) if(used[j]==0 && tallest<lcp[j]){
			tallest=lcp[j];
			ind=j;
		}
		used[ind]=1;
		u.unite(ind,ind+1,tallest);
	}
	printf("%d\n",u.dp[u.root(0)][K]);
	
	return 0;
}