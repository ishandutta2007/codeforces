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

string S[11];
int R,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,11)  getline(cin,S[i]);
	cin>>R>>C;
	R--,C--;
	R%=3,C%=3;
	int cnt=0;
	FOR(y,3) FOR(x,3) {
		if(S[R*4+y][C*4+x]=='.') S[R*4+y][C*4+x]='!',cnt++;
	}
	if(cnt==0) {
		FOR(y,11) FOR(x,11) if(S[y][x]=='.') S[y][x]='!';
	}
	FOR(y,11) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}