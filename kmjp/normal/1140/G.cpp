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
ll OE[303030];
int X[303030],Y[303030];
ll OO[303030],EE[303030];

vector<pair<int,ll>> E[303030];
vector<pair<int,ll>> E2[603030];
ll D[303030];
ll D2[603030][2];
int Q;
ll U[606060],V[606060];
ll ret[606060];

int vis[301010],id[303030];
int NV[301010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) NV[cur]+=dfs(e.first,cur);
	D2[cur*2][0]=D2[cur*2][1]=D2[cur*2+1][0]=D2[cur*2+1][1]=1LL<<60;
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) {
		int c = dfs2(e.first,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e.first];
		if(NV[e.first]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int col) {
	id[cur]=col;
	FORR(e,E[cur]) if(e.first!=pre && vis[e.first]==0) dfs3(e.first,cur,col);
}
	

void split(int cur,vector<int>& C) {
	if(vis[cur] || C.empty()) return;
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	vis[center]=1;
	
	vector<vector<int>> cand(E[center].size());
	int i;
	FOR(i,E[center].size()) if(vis[E[center][i].first]==0) dfs3(E[center][i].first,center,i);
	id[center]=-1;
	
	D2[center*2][0]=D2[center*2+1][1]=0;
	priority_queue<pair<ll,int>> PQ;
	PQ.push({0,center*2*2});
	PQ.push({0,(center*2+1)*2+1});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second/2;
		int t=PQ.top().second%2;
		PQ.pop();
		if(D2[cur][t]!=co) continue;
		FORR(e,E2[cur]) if(D2[e.first][t]>co+e.second) {
			D2[e.first][t]=co+e.second;
			PQ.push({-D2[e.first][t], e.first*2+t});
		}
	}
	
	FORR(c,C) {
		if(id[U[c]/2]==id[V[c]/2] && id[U[c]/2]!=-1) {
			cand[id[U[c]/2]].push_back(c);
		}
		else {
			ret[c]=min(D2[U[c]][0]+D2[V[c]][0],D2[U[c]][1]+D2[V[c]][1]);
		}
	}
	
	
	
	FOR(i,E[center].size()) if(vis[E[center][i].first]==0) split(E[center][i].first,cand[i]);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>OE[i];
	FOR(i,N-1) {
		cin>>X[i]>>Y[i]>>OO[i]>>EE[i];
		X[i]--;
		Y[i]--;
		E2[X[i]*2].push_back({Y[i]*2,OO[i]});
		E2[Y[i]*2].push_back({X[i]*2,OO[i]});
		E2[X[i]*2+1].push_back({Y[i]*2+1,EE[i]});
		E2[Y[i]*2+1].push_back({X[i]*2+1,EE[i]});
	}
	
	FOR(i,N) {
		E[N].push_back({i,OE[i]});
		D[i]=1LL<<60;
	}
	FOR(i,N-1) {
		E[X[i]].push_back({Y[i],OO[i]+EE[i]});
		E[Y[i]].push_back({X[i],OO[i]+EE[i]});
	}
	priority_queue<pair<ll,int>> PQ;
	PQ.push({0,N});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		
		if(D[cur]!=co) continue;
		FORR(e,E[cur]) if(D[e.first]>co+e.second) {
			D[e.first]=co+e.second;
			PQ.push({-D[e.first],e.first});
		}
	}
	
	FOR(i,N) {
		OE[i]=min(OE[i],D[i]);
		E2[i*2].push_back({i*2+1,OE[i]});
		E2[i*2+1].push_back({i*2,OE[i]});
	}
	
	cin>>Q;
	vector<int> cand;
	FOR(i,Q) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		cand.push_back(i);
	}
	
	split(0,cand);
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}