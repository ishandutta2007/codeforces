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

int N,M,K;
int TR[5050];
int TC[5050];
int CR[5050];
int CC[5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) {
		cin>>j>>x>>y;
		if(j==1) {
			TR[x-1]=i+1;
			CR[x-1]=y;
		}
		if(j==2) {
			TC[x-1]=i+1;
			CC[x-1]=y;
		}
	}
	FOR(y,N) {
		FOR(x,M) {
			if(TR[y]>TC[x]) _P("%d",CR[y]);
			else _P("%d",CC[x]);
			
			_P("%s",(x==M-1)?"\n":" ");
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}