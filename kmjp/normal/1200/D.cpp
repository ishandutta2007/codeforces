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


int N,K;
string S[2020];
int D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) {
		cin>>S[y];
		FORR(c,S[y]) c=c=='B';
	}
	
	FOR(y,N) {
		int L=N+1,R=-1;
		FOR(x,N) {
			if(S[y][x]) L=min(L,x), R=max(R,x);
		}
		if(R-L>=K+1) continue;
		if(L>R) D[0][0]++;
		else if(R-L<=K) {
			D[y+1][L+1]++;
			D[max(0,y-K+1)][L+1]--;
			D[y+1][max(0,R-K+1)]--;
			D[max(0,y-K+1)][max(0,R-K+1)]++;
			
		}
		
	}
	FOR(x,N) {
		int L=N+1,R=-1;
		FOR(y,N) if(S[y][x]) L=min(L,y), R=max(R,y);
		if(R-L>=K+1) continue;
		if(L>R) D[0][0]++;
		else if(R-L<=K) {
			D[L+1][x+1]++;
			D[L+1][max(0,x-K+1)]--;
			D[max(0,R-K+1)][x+1]--;
			D[max(0,R-K+1)][max(0,x-K+1)]++;
		}
	}
	
	int ma=0;
	FOR(y,N+1) {
		FOR(x,N+1) {
			if(y) D[y][x]+=D[y-1][x];
			if(x) D[y][x]+=D[y][x-1];
			if(y&&x) D[y][x]-=D[y-1][x-1];
			ma=max(ma,D[y][x]);
		}
	}
	cout<<ma<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}