#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int SX[2020],SY[2020];
int TX[2020],TY[2020];

int need[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>SX[i]>>SY[i];
	FOR(i,M) cin>>TX[i]>>TY[i];
	FOR(x,N) {
		FOR(y,M) if(SX[x]<=TX[y]&&SY[x]<=TY[y]) need[TX[y]-SX[x]]=max(need[TX[y]-SX[x]],TY[y]-SY[x]+1);
	}
	
	int mi=1<<30;
	for(i=1010000;i>=0;i--) {
		need[i]=max(need[i],need[i+1]);
		mi=min(mi,i+need[i]);
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}