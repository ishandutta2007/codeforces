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
string S;

struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
	static const ll mul0=10,mul1=10;
	static const ll add0=0, add1=0;
	static vector<ll> pmo[2];
	string s; int l; vector<ll> hash_[2];
	void init(string s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
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
vector<ll> RollingHash::pmo[2];

RollingHash rh;

void hoge(int a,int b,int c) {
	auto X=rh.hash(0,a-1);
	auto Y=rh.hash(a,a+b-1);
	auto Z=rh.hash(a+b,a+b+c-1);
	if(a>1 && S[0]=='0') return;
	if(b>1 && S[a]=='0') return;
	if(c>1 && S[a+b]=='0') return;
	
	if((X.first+Y.first)%1000000007!=Z.first) return;
	if((X.second+Y.second)%1000000009!=Z.second) return;
	
	
	cout<<S.substr(0,a)<<"+"<<S.substr(a,b)<<"="<<S.substr(a+b)<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) c-='0';
	rh.init(S);
	FORR(c,S) c+='0';
	for(int R=1;R<=N;R++) {
		for(int A=R-1;A<=R;A++) {
			int B=N-A-R;
			if(B<=0 || B>A) continue;
			hoge(A,B,R);
			if(A!=B) hoge(B,A,R);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}