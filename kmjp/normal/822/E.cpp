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

struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	string s; int l; vector<ll> hash_[2];
	void init(string s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

int maxmatch(RollingHash& S,int sp,RollingHash& T,int tp) {
	int L=0,R=min(S.s.size()-sp,T.s.size()-tp)+1;
	while(L+1<R) {
		int M=(L+R)/2;
		if(S.hash(sp,sp+M-1)==T.hash(tp,tp+M-1)) L=M;
		else R=M;
	}
	return L;
}

int N,M,X;
string S,T;
RollingHash RS,RT;
int dp[101010][32];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>M>>T;
	RS.init(S);
	RT.init(T);
	FOR(i,N+1) FOR(j,31) dp[i][j]=-202020;
	
	dp[0][0]=0;
	FOR(i,N) {
		FOR(j,31) {
			if(i) dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(dp[i][j]>=0) {
				int ml=maxmatch(RS,i,RT,dp[i][j]);
				if(ml>0) dp[i+ml][j+1]=max(dp[i+ml][j+1],dp[i][j]+ml);
			}
		}
	}
	
	cin>>X;
	for(i=1;i<=X;i++) if(dp[N][i]==M || dp[N-1][i]==M) return _P("YES\n");
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}