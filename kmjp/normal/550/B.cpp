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

int N,L,R,X;
int C[30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R>>X;
	FOR(i,N) cin>>C[i];
	int ret=0;
	for(int mask=0;mask<1<<N;mask++) {
		if(__builtin_popcount(mask)<2) continue;
		int ma=0,mi=1000000,tot=0;
		FOR(i,N) if(mask&(1<<i)) {
			tot+=C[i];
			mi=min(mi,C[i]);
			ma=max(ma,C[i]);
		}
		if(ma-mi>=X && L<=tot && tot<=R) ret++;
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