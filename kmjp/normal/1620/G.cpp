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
int C[23][26];
ll dp[1<<23];
ll F[1<<23];
ll G[1<<23];
const ll mo=998244353;

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) C[i][c-'a']++;
	}
	int mask,mask2;
	FOR(mask,1<<N) if(mask) {
		int C2[26];
		FOR(j,26) C2[j]=1<<20;
		FOR(i,N) if(mask&(1<<i)) {
			FOR(j,26) C2[j]=min(C2[j],C[i][j]);
		}
		F[mask]=1;
		FOR(j,26) (F[mask]*=C2[j]+1)%=mo;
		x=__builtin_popcount(mask);
		if(x%2==0) F[mask]=mo-F[mask];
	}
	
	FOR(i,N) {
		FOR(mask,1<<N) if(mask&(1<<i)) (F[mask]+=F[mask^(1<<i)])%=mo;
	}
	
	
	
	ll ret=0;
	FOR(mask,1<<N) {
		int k=0;
		int s=0;
		FOR(i,N) if(mask&(1<<i)) k++,s+=i+1;
		ret^=F[mask]*k*s;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}