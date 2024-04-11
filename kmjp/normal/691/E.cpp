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
ll K;
ll A[101];
ll mat[101][101][70];
ll vec[101];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>K;
	K--;
	FOR(i,N) cin>>A[i];
	FOR(x,N) FOR(y,N) mat[x][y][0]=(__builtin_popcountll(A[x]^A[y])%3==0);
	
	FOR(i,N) vec[i]=1;
	FOR(i,61) {
		FOR(x,N) FOR(y,N) FOR(z,N) (mat[x][y][i+1] += mat[x][z][i]*mat[z][y][i])%=mo;
		
		if(K & (1LL<<i)) {
			ll vec2[101];
			FOR(j,N) vec2[j]=vec[j], vec[j]=0;
			FOR(x,N) FOR(y,N) (vec[x] += vec2[y]*mat[y][x][i])%=mo;
		}
	}
	
	ll ret=0;
	FOR(i,N) ret+=vec[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}