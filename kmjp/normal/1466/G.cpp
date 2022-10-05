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

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
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
	pair<ll,ll> hash(VT s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

const ll mo=1000000007;

int N,Q;
string S[100],T;
RollingHash rh[100],trh;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int K;
string W;

ll p2[101010];
int C[101010][26];
ll num[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,101000) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>Q;
	cin>>S[0]>>T;
	
	rh[0].init(S[0]);
	FOR(i,T.size()) {
		FOR(j,26) C[i+1][j]=C[i][j];
		(C[i+1][T[i]-'a']+=p2[N-1-i])%=mo;
	}
	
	FOR(i,min(N,100)) {
		if(S[i].size()>=1000000) break;
		S[i+1]=S[i]+T[i]+S[i];
		rh[i+1].init(S[i+1]);
	}
	
	while(Q--) {
		cin>>K>>W;
		ll ret=0;
		trh.init(W);
		for(i=0;i+W.size()<=S[0].size();i++) {
			auto a=rh[0].hash(i,i+W.size()-1);
			if(a==trh.hash(0,W.size()-1)) ret+=p2[K];
		}
		FOR(i,W.size()) {
			int L=i;
			int R=W.size()-1-i;
			for(j=1;j<=K;j++) {
				if(S[j-1].size()>=max(L,R)) break;
			}
			if(j==K+1) continue;
			if(rh[j-1].hash(0,R-1)!=trh.hash(i+1,W.size()-1)) continue;
			if(rh[j-1].hash(S[j-1].size()-1-(i-1),S[j-1].size()-1)!=trh.hash(0,i-1)) continue;
			
			ll p=(mo+C[K][W[i]-'a']-C[j-1][W[i]-'a'])%mo;
			
			(ret+=p*modpow(p2[N-K]))%=mo;
			
		}
		
		cout<<ret%mo<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}