#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,S;
int U[303000],V[303000],W[303000];
int ME[303000],MW[303000];
ll dist[303000];
vector<pair<int,int> > E[303000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
		E[U[i]].emplace_back(V[i],i);
		E[V[i]].emplace_back(U[i],i);
	}
	
	cin>>S;
	FOR(i,N) dist[i]=1LL<<60;
	dist[--S]=0;
	
	priority_queue<pair<ll,int> > Q;
	Q.push(make_pair(0,S));
	
	ll tot=0;
	while(Q.size()) {
		auto rf=Q.top();
		Q.pop();
		x=rf.second;
		if(dist[x]!=-rf.first) continue;
		
		tot+=MW[x];
		
		FORR(r,E[x]) if(dist[r.first]>=dist[x]+W[r.second]) {
			if(dist[r.first]>dist[x]+W[r.second]) {
				dist[r.first]=dist[x]+W[r.second];
				Q.push(make_pair(-dist[r.first],r.first));
			}
			MW[r.first]=W[r.second];
			ME[r.first]=r.second+1;
		}
	}
	
	cout<<tot<<endl;
	FOR(i,N) if(ME[i]) cout<<ME[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}