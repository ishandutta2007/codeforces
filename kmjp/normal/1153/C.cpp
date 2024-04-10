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
string S;
int A[303030];
int B[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(N%2) return _P(":(\n");
	
	FOR(i,N) {
		A[i+1]=A[i];
		B[i+1]=B[i];
		if(S[i]=='(') A[i+1]++;
		if(S[i]==')') B[i+1]++;
	}
	
	int cur=0;
	FOR(i,N) {
		if(S[i]=='?') {
			int LA=A[N]-A[i];
			int LB=B[N]-B[i];
			int lef=N-i-LA-LB;
			if(cur+LA==LB+lef) S[i]=')';
			else S[i]='(';
		}
		if(S[i]=='(') cur++;
		if(S[i]==')') cur--;
		if(i!=N-1 && cur<=0) return _P(":(\n");
	}
	if(cur) return _P(":(\n");
	cout<<S<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}