#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
int mat[501][501],ma[501];
set<pair<int,int> > S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(y,N) {
		i=0;
		FOR(x,M) cin>>mat[y][x], i=(mat[y][x])?i+1:0, ma[y]=max(ma[y],i);
		S.insert(make_pair(-ma[y],y));
	}
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		mat[y][x]^=1;
		S.erase(make_pair(-ma[y],y));
		ma[y]=i=0;
		FOR(x,M) i=(mat[y][x])?i+1:0, ma[y]=max(ma[y],i);
		S.insert(make_pair(-ma[y],y));
		cout<<-S.begin()->first<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}