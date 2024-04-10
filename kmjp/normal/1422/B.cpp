#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,M;
int A[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(y,N) FOR(x,M) cin>>A[y][x];
		ll ret=0;
		FOR(y,N) FOR(x,M) {
			vector<ll> B;
			B.push_back(A[y][x]);
			if(y!=N-1-y) B.push_back(A[N-1-y][x]);
			if(x!=M-1-x) B.push_back(A[y][M-1-x]);
			if(y!=N-1-y&&x!=M-1-x) B.push_back(A[N-1-y][M-1-x]);
			sort(ALL(B));
			
			if(B.size()==2) {
				ret+=B[1]-B[0];
			}
			else if(B.size()==4) {
				ret+=(B[1]-B[0])+(B[2]+B[3]-2*B[1]);
			}
			
			A[y][x]=A[N-1-y][x]=A[y][M-1-x]=A[N-1-y][M-1-x]=0;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}