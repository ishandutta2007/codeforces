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

int N,M,K,S;
vector<int> E[101010];
int A[101010];
int D[101010][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S;
	FOR(i,N) cin>>A[i],A[i]--;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,K) {
		queue<int> Q;
		FOR(x,N) {
			if(A[x]==i) Q.push(x);
			else D[x][i]=1<<20;
		}
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(D[e][i]>D[x][i]+1) {
				D[e][i]=D[x][i]+1;
				Q.push(e);
			}
		}
	}
	FOR(i,N) {
		vector<int> V;
		FOR(j,K) V.push_back(D[i][j]);
		sort(ALL(V));
		ll ret=0;
		FOR(j,S) ret+=V[j];
		cout<<ret<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}