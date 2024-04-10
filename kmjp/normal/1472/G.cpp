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

int T,N,M;
vector<int> E[202020],RE[202020];
int D[202020],D2[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			RE[i].clear();
			D[i]=1<<20;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			RE[y-1].push_back(x-1);
		}
		D[0]=0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(D[e]>D[cur]+1) {
				D[e]=D[cur]+1;
				Q.push(e);
			}
		}
		priority_queue<pair<int,int>> PQ;
		FOR(i,N) {
			D2[i]=D[i];
			FORR(e,E[i]) D2[i]=min(D2[i],D[e]);
			PQ.push({-D2[i],i});
		}
		while(PQ.size()) {
			int co=-PQ.top().first;
			int cur=PQ.top().second;
			PQ.pop();
			if(D2[cur]!=co) continue;
			FORR(e,RE[cur]) if(D[e]<D[cur]&&D2[e]>D2[cur]) {
				D2[e]=D2[cur];
				PQ.push({-D2[e],e});
			}
		}
		FOR(i,N) cout<<D2[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}