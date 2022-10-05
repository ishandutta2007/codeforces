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
	pair<ll,ll> hash(string s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

int N,M;
string S;
string W[100000];
unordered_map<ll,int> L[1010];
RollingHash rh;
int from[10100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	rh.init(S);
	
	cin>>M;
	FOR(i,M) {
		cin>>W[i];
		s=W[i];
		reverse(ALL(s));
		FORR(r,s) r=tolower(r);
		RollingHash rh2;
		auto r=rh2.hash(s);
		L[s.size()][(r.first<<30)|r.second] = i;
	}
	MINUS(from);
	from[0]=0;
	FOR(i,N) if(from[i]>=0) {
		for(x=1;x<=1000 && i+x<=N;x++) {
			auto r=rh.hash(i,i+x-1);
			ll v=(r.first<<30)|r.second;
			if(L[x].count(v)) {
				from[i+x]=L[x][v];
			}
		}
	}
	
	x=N;
	vector<string> SS;
	while(x) {
		SS.push_back(W[from[x]]);
		x=x-W[from[x]].size();
	}
	reverse(ALL(SS));
	FORR(r,SS) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}