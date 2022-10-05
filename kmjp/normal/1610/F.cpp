#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
set<pair<int,int>> E[202020][2];
set<pair<int,int>> E2[202020];
int sum[202020];
int U[202020],V[202020],W[202020],ret[202020];
int num[202020];
int C[202020];

map<pair<int,int>,vector<pair<int,int>>> memo[2];

void dfs(int cur,int id,vector<pair<int,int>>& R) {
	if(E[cur][id].empty()) {
		return;
	}
	auto e=*E[cur][id].begin();
	E[cur][id].erase(E[cur][id].begin());
	E[e.first][id].erase({cur,e.second});
	R.push_back({e.first,e.second});
	dfs(e.first,id,R);
}

void dfs2(int cur) {
	if(E2[cur].empty()) {
		return;
	}
	auto e=*E2[cur].begin();
	E2[cur].erase(E2[cur].begin());
	int nex=e.first;
	int id=e.second;
	E2[nex].erase({cur,id});
	
	int x,y;
	if(memo[id].count({cur,nex})) {
		vector<pair<int,int>> R=memo[id][{cur,nex}];
		for(x=1;x<R.size();x++) {
			y=R[x].second;
			ret[y]=1+(V[y]==R[x].first);
		}
	}
	else {
		assert(memo[id].count({nex,cur}));
		vector<pair<int,int>> R=memo[id][{nex,cur}];
		for(x=R.size()-1;x>=1;x--) {
			y=R[x].second;
			ret[y]=1+(V[y]!=R[x].first);
		}
	}
	
	dfs2(nex);
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--,W[i]--;
		E[U[i]][W[i]].insert({V[i],i});
		E[V[i]][W[i]].insert({U[i],i});
		if(W[i]==0) sum[U[i]]^=1,sum[V[i]]^=1;
	}
	
	FOR(i,2) {
		FOR(j,N) if(E[j][i].size()%2==1) {
			vector<pair<int,int>> R;
			R.push_back({j,-1});
			dfs(j,i,R);
			x=R.back().first;
			memo[i][{j,x}]=R;
			/*
			cout<<i<<" "<<j<<" "<<x<<" ";
			FORR(r,R) cout<<r.first<<":"<<r.second<<" ";
			cout<<endl;
			*/
			E2[j].insert({x,i});
			E2[x].insert({j,i});
		}
	}
	FOR(i,2) {
		FOR(j,N) while(E[j][i].size()) {
			vector<pair<int,int>> R;
			R.push_back({j,-1});
			dfs(j,i,R);
			for(x=1;x<R.size();x++) {
				y=R[x].second;
				ret[y]=1+(V[y]==R[x].first);
			}
		}
	}
	FOR(i,N) if(E2[i].size()%2==1) dfs2(i);
	FOR(i,N) dfs2(i);
	
	int num=0;
	FOR(i,N) num+=sum[i];
	FOR(i,M) {
		assert(ret[i]>=1);
		if(ret[i]==1) {
			C[U[i]]-=W[i]+1;
			C[V[i]]+=W[i]+1;
		}
		else {
			C[V[i]]-=W[i]+1;
			C[U[i]]+=W[i]+1;
		}
	}
	FOR(i,N) {
		if(C[i]%2) assert(abs(C[i])==1);
	}
	
	
	cout<<num<<endl;
	FOR(i,M) cout<<ret[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}