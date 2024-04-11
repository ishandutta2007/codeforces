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

int N,S,E;
int X[5050],A[5050],B[5050],C[5050],D[5050];

map<pair<int,int>,ll> dp[5050];

void upd(int i,int x,int y,ll v) {
	if(dp[i].count({x,y})==0 || v<dp[i][{x,y}]) dp[i][{x,y}]=v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>E;
	S--, E--;
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>D[i];
	
	if(S==0) dp[0][{0,1}]=D[0];
	else if(E==0) dp[0][{1,0}]=B[0];
	else dp[0][{1,1}]=B[0]+D[0];
	
	for(i=1;i<N-1;i++) {
		FORR(r,dp[i-1]) {
			int nin = r.first.first;
			int nout = r.first.second;
			if(max(nin,nout)>N-i+2) continue;
			ll v = r.second + 1LL*(nin+nout)*(X[i]-X[i-1]);
			
			// both left
			if(nin&&nout&&i!=S&&i!=E) {
				x = nin-1;
				y = nout-1;
				ll v2=v+A[i]+C[i];
				if(x||y) upd(i,x,y,v2);
			}
			//both right
			if((nin||nout) && (i!=S&&i!=E)) {
				x = nin+1;
				y = nout+1;
				ll v2=v+B[i]+D[i];
				upd(i,x,y,v2);
			}
			
			// left to right
			if(nout&&i!=S) {
				x = nin;
				y = nout-1;
				ll v2 = v+A[i];
				if(i!=E) y++, v2 += D[i];
				upd(i,x,y,v2);
			}
			// right to left
			if(nin&&i!=E) {
				x = nin-1;
				y = nout;
				ll v2 = v+C[i];
				if(i!=S) x++, v2 += B[i];
				upd(i,x,y,v2);
			}
			// start right
			if(i==S) {
				x = nin;
				y = nout+1;
				ll v2 = v+D[i];
				upd(i,x,y,v2);
			}
			// get right
			if(i==E) {
				x = nin+1;
				y = nout;
				ll v2 = v+B[i];
				upd(i,x,y,v2);
			}
			
		}
		dp[i-1].clear();
	}
	
	// jump on
	ll ret;
	i = N-1;
	if(i==E) ret = X[i]-X[i-1] + dp[i-1][{0,1}] + A[i];
	else if(i==S) ret = X[i]-X[i-1] + dp[i-1][{1,0}] + C[i];
	else {
		ret = 2*(X[i]-X[i-1]) + dp[i-1][{1,1}] + A[i]+C[i];
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