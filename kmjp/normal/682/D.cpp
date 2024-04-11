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
string S,T;
int memo[1010][1010][11][2];

int dpdp(int x,int y,int k,int cont) {
	if(k==0 && cont==0) return 0;
	if(x==N || y==M) return (k==0)?0:-101010;
	if(memo[x][y][k][cont]) return memo[x][y][k][cont];
	int& ret=memo[x][y][k][cont];
	ret = -10101010;
	if(S[x]==T[y]) {
		if(k) ret = max(ret,1+dpdp(x+1,y+1,k-1,1));
		if(cont) ret = max(ret,1+dpdp(x+1,y+1,k,1));
	}
	ret = max(ret,dpdp(x+1,y,k,0));
	ret = max(ret,dpdp(x,y+1,k,0));
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ZERO(memo);
	
	cin>>N>>M>>K;
	cin>>S>>T;
	
	cout<<dpdp(0,0,K,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}