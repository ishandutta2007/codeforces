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
string S[101];
int NB;
int sum[105][105];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			sum[y+1][x+1]=sum[y][x+1]+sum[y+1][x]-sum[y][x]+(S[y][x]=='B');
			NB+=S[y][x]=='B';
		}
	}
	for(i=1;i<=min(H,W);i++) {
		FOR(y,H+1-i) FOR(x,W+1-i) {
			int num=sum[y+i][x+i]-sum[y+i][x]-sum[y][x+i]+sum[y][x];
			if(num==NB) return _P("%d\n",i*i-NB);
		}
	}
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}