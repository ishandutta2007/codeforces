#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,X,P;
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>P;
	int L=0,R=N;
	int sm=0,la=0;
	while(L<R) {
		int M=(L+R)/2;
		if(M==P) {
			L=M+1;
		}
		else if(M<P) {
			sm++;
			L=M+1;
		}
		else {
			la++;
			R=M;
		}
	}
	int les=X-1;
	int mor=N-X;
	ll ret=1;
	FOR(i,sm) ret=ret*(les--)%mo;
	FOR(i,la) ret=ret*(mor--)%mo;
	FOR(i,les+mor) ret=ret*(i+1)%mo;
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}