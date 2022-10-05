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

int N,M;
set<string> S,T;
int A[2];
int common;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>s;
		S.insert(s);
	}
	FOR(i,M) {
		cin>>s;
		if(S.count(s)) common++;
	}
	
	A[0]=N-common;
	A[1]=M-common;
	
	while(1) {
		if(common==0 && A[0]==0) {
			cout<<"NO"<<endl;
			return;
		}
		if(common) common--;
		else A[0]--;
		
		if(common==0 && A[1]==0) {
			cout<<"YES"<<endl;
			return;
		}
		if(common) common--;
		else A[1]--;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}