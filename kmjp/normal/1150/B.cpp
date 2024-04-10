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
string S[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	FOR(y,N-2) for(x=1;x<N-1;x++) if(S[y][x]=='.') {
		if(S[y+1][x]=='#') return _P("NO\n");
		if(S[y+2][x]=='#') return _P("NO\n");
		if(S[y+1][x-1]=='#') return _P("NO\n");
		if(S[y+1][x+1]=='#') return _P("NO\n");
		S[y][x]=S[y+1][x]=S[y+2][x]=S[y+1][x-1]=S[y+1][x+1]='#';
	}
	FOR(y,N) FOR(x,N) if(S[y][x]=='.') return _P("NO\n");
	cout<<"YES"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}