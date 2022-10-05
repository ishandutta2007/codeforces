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
vector<int> E[55];
double dp[55][55];
int V[55];

double comb(int P_,int Q_) {
	static const int N_=102;
	static double C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
void dfs(int cur,int pre) {
	V[cur]=0;
	dp[cur][0]=1;
	int i,x,y;
	FORR(e,E[cur]) if(e!=pre) {
		double tmp[55]={},tmp2[55]={};
		dfs(e,cur);
		// esubtreee-curxshrinksicur-prexshrinkcur
		// 
		FOR(x,V[e]+1) for(y=1;y<=V[e];y++) tmp[x]+=dp[e][min(x,y-1)]*(y<=x?0.5:1);
		FOR(x,V[cur]+1) FOR(y,V[e]+1) {
			tmp2[x+y]+=dp[cur][x]*tmp[y]*comb(x+y,y)*comb(V[e]+V[cur]-x-y,V[e]-y);
		}
		FOR(i,N+1) dp[cur][i]=tmp2[i];
		V[cur]+=V[e];
	}
	V[cur]++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	double F=1;
	for(i=1;i<=N-1;i++) F*=i;
	
	FOR(i,N) {
		ZERO(dp);
		dfs(i,-1);
		_P("%.12lf\n",dp[i][N-1]/F);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}