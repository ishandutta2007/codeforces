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
int A[303030][9];

pair<int,int> hoge(int v) {
	int pat[1<<8];
	int i,j,x,y;
	FOR(i,1<<M) pat[i]=-1;
	
	FOR(i,N) {
		int mask=0;
		FOR(j,M) if(A[i][j]>=v) mask|=1<<j;
		pat[mask]=i;
	}
	
	FOR(x,1<<M) FOR(y,1<<M) if((x|y)==(1<<M)-1 && pat[x]>=0 && pat[y]>=0) return {pat[x],pat[y]};
	return {-1,-1};
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(y,N) FOR(x,M) scanf("%d",&A[y][x]);
	
	pair<int,int> P={0,0};
	int ma=-1;
	for(i=29;i>=0;i--) {
		auto Q=hoge(ma+(1<<i));
		if(Q.first>=0) P=Q, ma+=1<<i;
	}
	
	
	cout<<P.first+1<<" "<<P.second+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}