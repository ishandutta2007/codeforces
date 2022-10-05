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
int P[505050];
string S;
ll DP[505050][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	cin>>S;
	
	ll ma=0;
	FOR(r,2) {
		
		ZERO(DP);
		FOR(i,N) {
			DP[i+1][0]=DP[i][0]+((S[i]=='B')?P[i]:0);
			DP[i+1][1]=DP[i][1]+((S[i]=='A')?P[i]:0);
			DP[i+1][1]=max(DP[i+1][1],DP[i][0]+((S[i]=='A')?P[i]:0));
			ma=max(ma,max(DP[i+1][0],DP[i+1][1]));
		}
		
		reverse(P,P+N);
		reverse(ALL(S));
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}