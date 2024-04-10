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

vector<pair<ll,int>> M[80][80];
int N,K;
ll mat[81][81];
int A[81];
ll ret=1LL<<60;

void dfs(vector<int>& V) {
	if(V.size()==K/2) {
		V.push_back(0);
		ll sum=0;
		int i;
		FOR(i,K/2) {
			FORR(a,M[V[i]][V[i+1]]) {
				if(A[a.second]==0) {
					sum+=a.first;
					break;
				}
			}
		}
		ret=min(ret,sum);
		V.pop_back();
		return;
	}
	
	int i;
	for(i=0;i<N;i++) {
		V.push_back(i);
		A[i]++;
		dfs(V);
		A[i]--;
		V.pop_back();
	}
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>K;
	FOR(y,N) FOR(x,N) cin>>mat[y][x];
	
	FOR(x,N) FOR(y,N) {
		FOR(z,N) if(z!=x && z!=y) {
			M[x][y].push_back(make_pair(mat[x][z]+mat[z][y],z));
		}
		FOR(i,10) M[x][y].push_back({1LL<<50,80});
		sort(ALL(M[x][y]));
	}
	vector<int> V;
	V.push_back(0);
	A[0]++;
	dfs(V);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}