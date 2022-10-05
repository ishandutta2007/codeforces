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
ll A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll sum=0;
	FOR(i,N) cin>>A[i], sum+=A[i];
	FOR(i,M) cin>>B[i];
	sort(A,A+N);
	sort(B,B+M);
	if(A[N-1]>B[0]) return _P("-1\n");
	
	ll ret=0;
	int ok=0;
	FOR(i,M) if(B[i]==A[N-1]) ok=1;
	if(ok==1) {
		FOR(i,M) ret+=sum+(B[i]-A[N-1]);
	}
	else {
		if(M==1||N==1) return _P("-1\n");
		FOR(i,M) {
			if(i==0) ret+=sum+(B[i]-A[N-2]);
			else ret+=sum+(B[i]-A[N-1]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}