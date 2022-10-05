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

int H,W;
string S[120];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int L=150,R=0,U=150,D=0;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='B') {
			L=min(L,x);
			R=max(R,x);
			U=min(U,y);
			D=max(D,y);
		}
	}
	cout<<(D+U)/2+1<<" "<<(L+R)/2+1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}