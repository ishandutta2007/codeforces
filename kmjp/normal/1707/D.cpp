#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int mo;
vector<int> E[2020];
ll dp[2020][2020];
ll S[2020][2020];
ll D[2020][2020];

ll comb(int P_,int Q_) {
	static const int N_=2020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}


void dfs(int cur,int pre) {
	int i,j;
	vector<vector<ll>> L,R;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) {
		E[cur].erase(E[cur].begin()+i);
		break;
	}
	int C=E[cur].size();
	FORR(e,E[cur]) dfs(e,cur);
	
	L.resize(C+2),R.resize(C+2);
	L[0].resize(N+1,1);
	R[C+1].resize(N+1,1);
	FOR(i,C) {
		FOR(j,N+1) L[i+1].push_back(L[i][j]*S[E[cur][i]][j]%mo);
	}
	for(i=C-1;i>=0;i--) {
		FOR(j,N+1) R[i+1].push_back(R[i+2][j]*S[E[cur][i]][j]%mo);
	}
		
	if(cur) {
		FOR(i,C) {
			ll a=0;
			for(j=1;j<=N;j++) {
				(dp[cur][j]+=a*dp[E[cur][i]][j])%=mo;
				(a+=L[i][j]*R[i+2][j])%=mo;
			}
		}
	}
	for(i=1;i<=N;i++) {
		D[cur][i]=L[C][i];
		(dp[cur][i]+=D[cur][i])%=mo;
		S[cur][i]=(dp[cur][i]+S[cur][i-1])%mo;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	
	ll ret[2020]={};
	for(i=1;i<=N-1;i++) {
		ret[i]=dp[0][i];
		FOR(j,i) ret[i]+=mo-comb(i,j)*ret[j]%mo;
		ret[i]%=mo;
		cout<<ret[i]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}