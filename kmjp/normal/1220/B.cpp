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
int M[1010][1010];
int A[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>M[y][x];
	int G=0;
	FOR(x,N) G=__gcd(G,M[0][x]);
	
	for(i=1;i<=40000;i++) if(G%i==0) {
		vector<int> V={i,G/i};
		FORR(v,V) {
			A[0]=v;
			for(x=1;x<N;x++) A[x]=M[0][x]/A[0];
			int ok=1;
			FOR(y,N) FOR(x,y) if(1LL*A[x]*A[y]!=M[x][y]) {
				ok=0;
				break;
			}
			
			if(ok) {
				FOR(i,N) cout<<A[i]<<" ";
				return;
			}
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}