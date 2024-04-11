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
string S;
ll pre[2020][2020];
ll post[2020][2020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	
	pre[0][0]=1;
	FOR(i,2010) {
		FOR(j,2010) if(pre[i][j]) {
			(pre[i+1][j+1]+=pre[i][j])%=mo;
			if(j) (pre[i+1][j-1]+=pre[i][j])%=mo;
		}
	}
	
	int dif=0,mi=0;
	FORR(c,S) {
		if(c=='(') dif++;
		else dif--, mi=min(mi,dif);
	}
	
	ll ret=0;
	for(i=0;i<=N-M;i++) {
		FOR(j,2010) if(pre[i][j]) {
			if(j+mi<0) continue;
			x=j+dif;
			y=N-M-i;
			if(x>y) continue;
			(ret += pre[i][j]*pre[y][x])%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}