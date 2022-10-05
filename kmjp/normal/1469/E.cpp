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

int T,N,K;
string S;

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333332;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%5259,mul1=10007+(((ll)&mul1)>>5)%4257;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		FORR(c,S) c^=1;
		
		RollingHash rh;
		rh.init(S);
		set<pair<int,int>> T;
		for(i=0;i+K<=N;i++) T.insert(rh.hash(i,i+K-1));
		
		string ret;
		FOR(i,1<<min(K,20)) {
			string R=string(K,'0');
			FOR(j,min(K,20)) if(i&(1<<j)) R[K-1-j]='1';
			rh.init(R);
			if(T.count(rh.hash(0,K-1))==0) {
				ret=R;
				break;
			}
		}
		
		if(ret.empty()) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			cout<<ret<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}