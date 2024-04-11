#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,M;
ll ret;

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>S;
	
	ret += N*(M-1);
	FOR(x,N-1) if(S[x]!=S[x+1]) ret+=N*(M-1);
	
	int cur=0;
	for(x=1;x<N;x++) {
		if(S[x-1]==S[x]) {
			cur=0;
		}
		else {
			if(x>1 && S[x]!=S[x-2]) cur=0;
			cur++;
		}
		ret-=cur;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}