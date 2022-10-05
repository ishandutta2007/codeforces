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

int N,X,Y;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		int ok=1;
		for(j=max(0,i-X);j<i;j++) if(A[j]<=A[i]) ok=0;
		for(j=i+1;j<=min(N-1,i+Y);j++) if(A[j]<=A[i]) ok=0;
		if(ok) {
			cout<<i+1<<endl;
			break;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}