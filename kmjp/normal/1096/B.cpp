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
ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S[0]==S.back()) {
		ll L=0,R=N-1;
		while(S[L]==S[0]) L++;
		while(S[R]==S[0]) R--;
		
		cout<<(((L+1)*(N-1-R+1))%mo)<<endl;
	}
	else {
		int L=0,R=N-1;
		while(S[L]==S[0]) L++;
		while(S[R]==S.back()) R--;
		cout<<L+(N-R)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}