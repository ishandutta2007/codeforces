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
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ok=1;
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		if(ok && S[i][0]=='O' && S[i][1]=='O') S[i][0]=S[i][1]='+', ok=0;
		if(ok && S[i][3]=='O' && S[i][4]=='O') S[i][3]=S[i][4]='+', ok=0;
	}
	if(ok) return _P("NO\n");
	cout<<"YES"<<endl;
	FOR(i,N) cout<<S[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}