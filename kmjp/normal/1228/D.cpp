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

int N,M;
vector<int> E[101010];
int C[101010],num[4];
ll H[101010];

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	vector<int> s; int l; vector<ll> hash_[2];
	void init(vector<int> s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	ll hash(vector<int> s) { init(s); return hash(0,s.size()-1); }
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash rh;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	map<ll,int> mp;
	for(i=1;i<=N;i++) {
		sort(ALL(E[i]));
		H[i]=rh.hash(E[i]);
		mp[H[i]]=0;
	}
	if(mp.size()!=3) return _P("-1\n");
	
	x=0;
	FORR(m,mp) m.second=++x;
	for(i=1;i<=N;i++) {
		C[i]=mp[H[i]];
		num[C[i]]++;
	}
	for(i=1;i<=N;i++) {
		if(E[i].size()!=N-num[C[i]]) return _P("-1\n");
		FORR(e,E[i]) if(C[e]==C[i]) return _P("-1\n");
	}
	
	for(i=1;i<=N;i++) cout<<C[i]<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}