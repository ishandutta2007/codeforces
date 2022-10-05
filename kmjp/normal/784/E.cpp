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

int A[4];
int B[4];
int C[2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>A[i];
	B[0] = A[0] ^ A[1];
	B[1] = A[2] | A[3];
	B[2] = A[1] & A[2];
	B[3] = A[0] ^ A[3];
	C[0] = B[0] & B[1];
	C[1] = B[2] | B[3];
	cout<<(C[0]^C[1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}