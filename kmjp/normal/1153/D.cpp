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
int G[303030];
int P[303030];
vector<int> E[303030];
pair<int,int> D[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>G[i];
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	
	for(i=N-1;i>=0;i--) {
		if(E[i].empty()) {
			D[i]={1,1};
		}
		else if(G[i]==1) {
			int mi=303030;
			FORR(e,E[i]) {
				D[i].first+=D[e].first;
				mi=min(mi,D[e].first-D[e].second);
			}
			D[i].second=D[i].first-mi;
		}
		else {
			FORR(e,E[i]) {
				D[i].first+=D[e].first;
				D[i].second+=D[e].second-1;
			}
			D[i].second++;
		}
	}
	cout<<D[0].second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}