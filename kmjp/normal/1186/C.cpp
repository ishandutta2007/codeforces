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

int S[1010101];
int C;

int N;
string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	N=A.size();
	FOR(i,N) {
		S[i+1]=S[i];
		if(A[i]=='1') S[i+1]++;
	}
	FORR(b,B) if(b=='1') C++;
	
	int ret=0;
	for(i=B.size();i<=N;i++) {
		x=S[i]-S[i-B.size()];
		if(x%2==C%2) ret++;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}