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
	static const ll mo0=1000000021,mo1=1000000009;
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
	/*ll*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

ll mo=1000000007;
ll dp[3030];
int invalid[16];
ll ret[3030];
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	string S;
	FOR(i,N) {
		cin>>x;
		S.push_back(x);
	}
	reverse(ALL(S));
	RollingHash rh;
	rh.init(S);
	
	invalid[3]=invalid[5]=invalid[14]=invalid[15]=1;
	unordered_set<ll> T[3030];
	ll ret=0;
	for(x=N-1;x>=0;x--) {
		ZERO(dp);
		dp[x]=1;
		for(y=x;y<=N;y++) {
			if(x!=y) {
				ll h=rh.hash(x,y-1);
				if(T[y-x].count(h)==0) {
					T[y-x].insert(h);
					(ret+=dp[y])%=mo;
				}
			}
			(dp[y+1]+=dp[y])%=mo;
			(dp[y+2]+=dp[y])%=mo;
			(dp[y+3]+=dp[y])%=mo;
			int mask=(S[y]<<0)|(S[y+1]<<1)|(S[y+2]<<2)|(S[y+3]<<3);
			if(invalid[mask]==0) (dp[y+4]+=dp[y])%=mo;
		}
		cout<<ret<<endl;
	}
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}