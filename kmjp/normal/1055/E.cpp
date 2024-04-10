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

int N,S,M,K;
int A[2020],B[2020];
int L[2020],R[2020];
vector<int> V;

int MR[2020];
int dp[1600][1600];

int ok(int v) {
	int i,j;
	FOR(i,N) B[i+1]=B[i]+(A[i]<=v);
	
	ZERO(dp);
	FOR(i,N) {
		FOR(j,M) {
			if(MR[i]>i) {
				dp[MR[i]][j+1]=max(dp[MR[i]][j+1],dp[i][j]+B[MR[i]]-B[i]);
				if(dp[MR[i]][j+1]>=K) return 1;
			}
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(A[i]);
	}
	FOR(i,S) {
		cin>>L[i]>>R[i];
		for(j=L[i]-1;j<R[i];j++) MR[j]=max(MR[j],R[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	if(ok(V.back())==0) return _P("-1\n");
	
	int ret=V.size()-1;
	for(i=12;i>=0;i--) {
		if(ret>=(1<<i) && ok(V[ret-(1<<i)])) ret-=1<<i;
	}
	cout<<V[ret]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}