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

int Q,N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>S>>T;
		string A=S,B=T;
		sort(ALL(A));
		sort(ALL(B));
		if(A!=B) {
			cout<<"NO"<<endl;
			continue;
		}
		FOR(i,N-1) if(A[i]==A[i+1]) break;
		if(i<N-1) {
			cout<<"YES"<<endl;
			continue;
		}
		
		int rev=0;
		FOR(i,N) {
			FOR(j,i) if(S[j]>S[i]) rev^=1;
			FOR(j,i) if(T[j]>T[i]) rev^=1;
		}
		if(rev==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}