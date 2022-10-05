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

int N;
ll A[101010];

ll dp[101010][62];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) A[i]=A[N-1]-A[i];
	sort(A,A+N);
	FOR(i,N+1) FOR(j,62) dp[i][j]=1LL<<60;
	dp[0][0]=0;
	FOR(i,60) {
		vector<pair<ll,ll>> V;
		FOR(j,N) V.push_back({A[j]&((1LL<<i)-1), A[j]});
		sort(ALL(V));
		vector<int> C[2];
		C[0].push_back(0);
		C[1].push_back(0);
		FOR(j,N) {
			C[0].push_back(C[0].back());
			C[1].push_back(C[1].back());
			C[(V[j].second>>i)%2].back()++;
		}
		int T[2]={C[0].back(),C[1].back()};
		FOR(j,N+1) { // num of carry
			int n1,carry;
			// 0
			n1=C[1][N-j]+C[0][N]-C[0][N-j];
			carry=C[1][N]-C[1][N-j];
			dp[carry][i+1]=min(dp[carry][i+1],dp[j][i]+n1);
			// 1
			n1=C[1][N]-C[1][N-j]+C[0][N-j];
			carry=N-C[0][N-j];
			dp[carry][i+1]=min(dp[carry][i+1],dp[j][i]+n1);
		}
	}
	
	cout<<dp[0][60]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}