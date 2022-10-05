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

int N,Q,M;
const int DI=50;
int A[300000];
int dp[10000][2][32];
int S[10000];


inline int nex(int cur,int a) {
	if(a==0) cur = (cur<<1) | 1;
	else cur = (cur<<1) | (cur!=(1<<M)-1);
	return cur&((1<<M)-1);
}

int update(int v,int l,int r) {
	int i,t;
	
	if(S[v]) {
		FOR(i,DI) A[DI*v+i]^=1;
		S[v]=0;
	}
	for(i=l;i<r;i++) A[DI*v+i]^=1;
	
	
	for(int mask=0;mask<1<<M;mask++) {
		
		FOR(t,2) {
			int cur=mask;
			for(i=DI-1;i>=0;i--) cur=nex(cur,A[DI*v+i]^t);
			dp[v][t][mask]=cur;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) {
		ll l;
		cin>>l;
		A[i]=l%2;
	}
	FOR(i,250000/DI) update(i,0,0);
	while(Q--) {
		int T,L,R;
		cin>>T>>L>>R;
		L--;
		if(T==1) {
			ll l;
			cin>>l;
			if(l%2==0) continue;
			while(L/DI != R/DI) {
				if(L%DI==0) {
					S[L/DI]^=1;
					L+=DI;
				}
				else {
					update(L/DI,L%DI,DI);
					L+=DI-(L%DI);
				}
			}
			update(L/DI,L%DI,R%DI);
		}
		else {
			int cur=(1<<M)-1;
			while(R>L && R%DI!=0) R--, cur=nex(cur,A[R]^S[R/DI]);
			while(R>=L+DI) R-=DI, cur=dp[R/DI][S[R/DI]][cur];
			while(R>L) R--, cur=nex(cur,A[R]^S[R/DI]);
			
			cout<<2-(cur&1)<<endl;
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}