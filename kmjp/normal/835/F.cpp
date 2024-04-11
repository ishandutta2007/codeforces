#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
set<pair<int,int>> E[202020];
ll ntot[202020];
int vis[202020];
vector<pair<int,ll>> V;
map<pair<int,int>,int> M;
vector<ll> chi[202020];

void dfs(int cur,ll tot) {
	if(vis[cur]) return;
	vis[cur]=1;
	V.push_back({cur,tot});
	FORR(e,E[cur]) dfs(e.first,tot+e.second);
}

ll X[202020],L[202020];
ll Rdia[202020],Rma[202020];
ll Ldia[202020],Lma[202020];
ll tma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y>>r;
		E[x-1].insert({y-1,r});
		E[y-1].insert({x-1,r});
		M[{x-1,y-1}]=M[{y-1,x-1}]=r;
	}
	queue<int> Q;
	FOR(i,N) if(E[i].size()==1) Q.push(i);
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		auto r=*E[cur].begin();
		E[cur].clear();
		int tar=r.first;
		int co=r.second;
		E[tar].erase({cur,co});
		
		chi[cur].push_back(0);
		chi[cur].push_back(0);
		sort(ALL(chi[cur]));
		reverse(ALL(chi[cur]));
		tma=max(tma,chi[cur][0]+chi[cur][1]);
		
		chi[tar].push_back(chi[cur][0]+co);
		ntot[cur]=-1;
		if(E[tar].size()==1) Q.push(tar);
	}
	
	FOR(i,N) if(ntot[i]>=0) {
		chi[i].push_back(0);
		chi[i].push_back(0);
		sort(ALL(chi[i]));
		reverse(ALL(chi[i]));
		tma=max(tma,chi[i][0]+chi[i][1]);
		ntot[i]=chi[i][0];
	}
	FOR(i,N) if(ntot[i]>=0) {
		dfs(i,0);
		break;
	}
	
	int C=V.size();
	FOR(i,C) {
		X[i]=V[i].second;
		L[i]=ntot[V[i].first];
	}
	ll tot=V.back().second + M[{V[0].first,V.back().first}];
	
	ll mi=1LL<<60;
	ll RR=0,LL=1LL<<60;
	for(i=C-1;i>=0;i--) {
		Rma[i]=max(Rma[i+1],tot-X[i]+L[i]);
		Rdia[i]=max({Rdia[i+1],RR-X[i]+L[i],L[i]});
		RR=max(RR,X[i]+L[i]);
	}
	
	FOR(i,C) {
		Lma[i]=max(i?Lma[i-1]:0,X[i]+L[i]);
		Ldia[i]=max({i?Ldia[i-1]:0,X[i]+L[i]-LL,L[i]});
		LL=min(LL,X[i]-L[i]);
		
		if(i==C-1) {
			mi=min(mi,Ldia[i]);
		}
		else {
			mi=min(mi,max({Ldia[i],Rdia[i+1],Lma[i]+Rma[i+1]}));
		}
	}
	cout<<max(tma,mi)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}