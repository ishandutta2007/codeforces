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
string S[505050];
int M[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int X=0,Y=1023;
	FOR(i,N) {
		cin>>S[i]>>M[i];
		
		if(S[i]=="^") {
			X ^= M[i];
			Y ^= M[i];
		}
		if(S[i]=="&") {
			X &= M[i];
			Y &= M[i];
		}
		if(S[i]=="|") {
			X |= M[i];
			Y |= M[i];
		}
	}
	
	int C[3]={};
	FOR(i,10) {
		x=1<<i;
		if((X&x) && (Y&x)) C[1] |= x;
		if((X&x) && (Y&x)==0) C[0] |= x;
		if((X&x) || (Y&x)) C[2] |= x;
	}
	
	_P("3\n");
	_P("^ %d\n",C[0]);
	_P("| %d\n",C[1]);
	_P("& %d\n",C[2]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}