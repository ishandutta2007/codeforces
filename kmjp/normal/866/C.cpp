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

int N,R;
int F[101],S[101];
double P[101];
double dp[52][5250];
double prob[52][5250];


double hoge(double v) {
	int i,j;
	ZERO(dp);
	for(i=R+1;i<=5200;i++) dp[N][i]=v;
	for(int i=N-1;i>=0;i--) {
		FOR(j,5001) {
			dp[i][j]+=(F[i]+dp[i+1][j+F[i]])*P[i];
			dp[i][j]+=(S[i]+dp[i+1][j+S[i]])*(1-P[i]);
			dp[i][j]=min(dp[i][j],v);
		}
	}
	return dp[0][0];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>R;
	double LL=0,RR=1e9;
	FOR(i,N) {
		cin>>F[i]>>S[i]>>P[i];
		LL+=F[i];
		P[i]/=100.0;
	}
	
	FOR(i,R+1) prob[N][i]=1;
	for(i=N-1;i>=0;i--) {
		FOR(j,5001) {
			prob[i][j]+=prob[i+1][j+F[i]]*P[i];
			prob[i][j]+=prob[i+1][j+S[i]]*(1-P[i]);
		}
	}
	
	
	FOR(i,90) {
		double M=(LL+RR)/2;
		if(hoge(M)<M) RR=M;
		else LL=M;
	}
	
	_P("%.12lf\n",(LL+RR)/2.0);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}