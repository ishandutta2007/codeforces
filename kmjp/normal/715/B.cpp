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

int N,M;
ll L;
int S,T;
vector<pair<int,int>> E[101010];

int U[101010],V[101010];
ll W[101010],W2[101010];
const ll D=10000000000000LL;
ll DD[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L>>S>>T;
	
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		W2[i]=W[i];
		if(W[i]==0) W[i]=1;
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
	}
	
	again:
	FOR(i,N) DD[i]=1LL<<60;
	DD[S]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,S});
	
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		
		Q.pop();
		if(DD[cur]!=co) continue;
		FORR(e,E[cur]) if(DD[e.first]>co+W[e.second]) {
			DD[e.first]=co+W[e.second];
			Q.push({-DD[e.first],e.first});
		}
	}
	if(DD[T]>L) return _P("NO\n");
	
	if(DD[T]<L) {
		FOR(i,M) if(W2[i]==0) {
			W[i]+=L-DD[T];
			W2[i]=1;
			goto again;
		}
		if(i>=M) return _P("NO\n");
	}
	
	cout<<"YES"<<endl;
	FOR(i,M) cout<<U[i]<<" "<<V[i]<<" "<<W[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}