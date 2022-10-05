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

int N,M,K;
vector<int> E[202020];
vector<int> V;
int D[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>x;
		V.push_back(x-1);
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,2) {
		FOR(j,N) D[i][j]=1<<20;
		queue<int> Q;
		if(i==0) {
			D[i][0]=0;
			Q.push(0);
		}
		else {
			D[i][N-1]=0;
			Q.push(N-1);
		}
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(D[i][e]>D[i][x]+1) {
				D[i][e]=D[i][x]+1;
				Q.push(e);
			}
		}
	}
	int mi=D[0][N-1];
	vector<pair<int,int>> cand;
	FORR(v,V) {
		cand.push_back({D[0][v]-D[1][v],v});
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	set<int> S;
	int ma=0;
	FORR(c,cand) {
		if(S.size()) {
			ma=max(ma,D[0][c.second]+1+*S.rbegin());
		}
		S.insert(D[1][c.second]);
	}
	if(ma==0) ma=mi;
	cout<<min(mi,ma)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}