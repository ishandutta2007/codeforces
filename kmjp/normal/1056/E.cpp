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
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	pair<ll,ll> hash(string s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

int num[2];
string S,T;
int L;
RollingHash rh;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	L=T.size();
	rh.init(T);
	
	
	if(S[0]=='1') {
		FORR(c,S) c^=1;
	}
	
	x=10101010;
	FOR(i,S.size()) {
		num[S[i]-'0']++;
		if(S[i]=='1') x=min(x,i);
	}
	
	int ret=0;
	for(int l0=1;1LL*l0*num[0]<L;l0++) {
		ll s0=1LL*l0*num[0];
		if(s0>L) continue;
		if((L-s0)%num[1]) continue;
		int l1=(L-s0)/num[1];
		if(l1<=0) continue;
		
		pair<ll,ll> H[2];
		H[0]=rh.hash(0,l0-1);
		H[1]=rh.hash(l0*x,l0*x+l1-1);
		if(H[0]==H[1]) continue;
		
		int cur=0;
		FOR(i,S.size()) {
			if(S[i]=='0') {
				if(H[0]!=rh.hash(cur,cur+l0-1)) break;
				cur+=l0;
			}
			else {
				if(H[1]!=rh.hash(cur,cur+l1-1)) break;
				cur+=l1;
			}
		}
		if(i==S.size()) ret++;
		
		
		
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}