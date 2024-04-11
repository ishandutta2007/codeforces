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

string S,T;
int LS,LT;

int LC[2][2120][2120];

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>S>>T;
	LS=S.size();
	LT=T.size();
	
	for(x=LS-1;x>=0;x--) for(y=LT-1;y>=0;y--) {
		if(S[x]==T[y]) LC[0][x][y]=LC[0][x+1][y+1]+1;
		if(S[LS-1-x]==T[y]) LC[1][x][y]=LC[1][x+1][y+1]+1;
	}
	
	vector<pair<int,int>> R;
	int cur=0;
	while(cur<LT) {
		int ma=0;
		pair<int,int> p;
		FOR(y,LS) {
			if(LC[0][y][cur]>ma) ma=LC[0][y][cur], p=make_pair(y,y+ma-1);
			if(LC[1][y][cur]>ma) ma=LC[1][y][cur], p=make_pair(LS-1-y,LS-1-y-(ma-1));
		}
		cur+=ma;
		if(ma==0) return _P("-1\n");
		R.push_back(p);
	}
	
	_P("%d\n",R.size());
	FORR(r,R) _P("%d %d\n",r.first+1,r.second+1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}