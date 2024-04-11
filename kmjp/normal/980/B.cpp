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

int N,K;
string S[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,4) S[i]=string(N,'.');
	
	if(K%2==0) {
		FOR(x,K/2) S[1][x+1]=S[2][x+1]='#';
	}
	else if(K<=N-2) {
		FOR(x,K) S[1][(N-K)/2+x]='#';
	}
	else {
		FOR(x,N-2) S[1][x+1]=S[2][x+1]='#';
		FOR(x,2*(N-2)-K) S[1][x+2]='.';
	}
	
	cout<<"YES"<<endl;
	FOR(i,4) cout<<S[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}