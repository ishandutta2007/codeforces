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

int N,K;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K>>S;
	
	FOR(i,N) {
		if(S[i]-'a'>=13) {
			x=min(S[i]-'a',K);
			K-=x;
			S[i]-=x;
		}
		else {
			x=min('z'-S[i],K);
			K-=x;
			S[i]+=x;
		}
	}
	if(K) cout<<-1<<endl;
	else cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}