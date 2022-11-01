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
int n,m;
int vis[105],mark[105];
vector<int> g[105];
int whole,loop;
void prep(int v,int c,int rev=-1){
	++whole;
	mark[v]=c;
	vis[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(mark[to]==0) prep(to,-c,v);
		else if(to!=rev) loop=1;
	}
}

int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(vis,0,sizeof(vis));
	int res=0,odd=0;
	REP(i,n) if(!vis[i]){
		memset(mark,0,sizeof(mark));
		whole=loop=0;
		prep(i,1);
		if(whole&1 && loop) ++res;
		else if(whole&1) ++odd;
	}
	cout<<res+(odd%2)<<endl;

	return 0;
}