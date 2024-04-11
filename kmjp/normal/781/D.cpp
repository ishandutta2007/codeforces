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
bitset<512> ok[512][63][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		ok[x-1][0][r][y-1]=1;
	}
	FOR(i,61) FOR(x,N) FOR(y,N) {
		if(ok[x][i][0][y]) ok[x][i+1][0] |= ok[y][i][1];
		if(ok[x][i][1][y]) ok[x][i+1][1] |= ok[y][i][0];
	}
	
	
	bitset<512> cur;
	cur[0]=1;
	int flip=0;
	ll ret=0;
	for(i=60;i>=0;i--) {
		bitset<512> nex;
		FOR(x,N) if(cur[x]) nex |= ok[x][i][flip];
		if(nex.count()) {
			cur=nex;
			ret += 1LL<<i;
			flip ^= 1;
		}
	}
	if(ret>1000000000000000000LL) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}