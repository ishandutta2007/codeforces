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
int D[101][101];
int memo[101][101][101];

int win(int a,int b,int pre) {
	if(memo[a][b][pre]>=0) return memo[a][b][pre];
	int ret=0;
	int i;
	FOR(i,N) if(D[a][i]>=pre && win(b,i,D[a][i])==0) ret=1;
	return memo[a][b][pre]=ret;
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>s;
		D[x-1][y-1]=s[0]-'a'+2;
	}
	
	MINUS(memo);
	
	FOR(x,N) {
		FOR(y,N) {
			if(win(x,y,1)) cout<<"A";
			else cout<<"B";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}