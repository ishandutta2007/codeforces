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

int H,W,K;
int X[505],Y[505];

int dp[1005][1005];

int ok(int v) {
	vector<int> Xs,Ys;
	
	Xs.push_back(0);
	Ys.push_back(0);
	Xs.push_back(W);
	Ys.push_back(H);
	int i;
	FOR(i,K) {
		Xs.push_back(max(X[i]-v,0));
		Xs.push_back(min(X[i]+v+1,W));
		Ys.push_back(max(Y[i]-v,0));
		Ys.push_back(min(Y[i]+v+1,H));
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	ZERO(dp);
	FOR(i,K) {
		int xs=lower_bound(ALL(Xs),max(X[i]-v,0))-Xs.begin();
		int xe=lower_bound(ALL(Xs),min(X[i]+v+1,W))-Xs.begin();
		int ys=lower_bound(ALL(Ys),max(Y[i]-v,0))-Ys.begin();
		int ye=lower_bound(ALL(Ys),min(Y[i]+v+1,H))-Ys.begin();
		dp[ys][xs]++;
		dp[ye][xe]++;
		dp[ys][xe]--;
		dp[ye][xs]--;
	}
	int L=W,R=-1,U=H,D=-1;
	int y,x;	
	FOR(y,Ys.size()-1) FOR(x,Xs.size()-1) {
		if(y && x) dp[y][x] += dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1];
		else if(y) dp[y][x]+=dp[y-1][x];
		else if(x) dp[y][x]+=dp[y][x-1];
		
		if(dp[y][x]==0) {
			L=min(L,Xs[x]);
			R=max(R,Xs[x+1]-1);
			U=min(U,Ys[y]);
			D=max(D,Ys[y+1]-1);
		}
	}
	
	if(R-L+1 > 2*v+1) return 0;
	if(D-U+1 > 2*v+1) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>K;
	FOR(i,K) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
	}
	int ret=(1<<30)-1;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}