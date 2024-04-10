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

int N,M,Q;
string S,T;

int ok[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q>>S>>T;
	FOR(i,N) {
		ok[i+1]=ok[i];
		if(i+M<=N) {
			x=1;
			FOR(j,M) if(S[i+j]!=T[j]) x=0;
			ok[i+1]+=x;
		}
	}
	
	while(Q--) {
		cin>>x>>y;
		y-=M-1;
		if(y<x) {
			cout<<0<<endl;
		}
		else {
			cout<<ok[y]-ok[x-1]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}