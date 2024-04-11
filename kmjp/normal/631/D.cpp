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
ll NL[202020];
char NC[202020];
ll ML[202020];
char MC[202020];

struct RollingHash {
	static const ll mo0=1000000007,mo1=1000000009;
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
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

RollingHash NH,MH;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>s;
		NC[i]=s.back();
		NL[i]=atoi(s.substr(0,s.size()-2).c_str());
		if(i&&NC[i]==NC[i-1]) {
			NL[i-1]+=NL[i];
			i--;
			N--;
		}
	}
	FOR(i,M) {
		cin>>s;
		MC[i]=s.back();
		ML[i]=atoi(s.substr(0,s.size()-2).c_str());
		if(i&&MC[i]==MC[i-1]) {
			ML[i-1]+=ML[i];
			i--;
			M--;
		}
	}
	
	ll ret=0;
	if(M==1) {
		FOR(i,N) if(NC[i]==MC[0] && NL[i]>=ML[0]) ret+=NL[i]-ML[0]+1;
	}
	else {
		vector<int> nv,mv;
		FOR(i,N) nv.push_back(NC[i]+NL[i]*100);
		FOR(i,M) mv.push_back(MC[i]+ML[i]*100);
		NH.init(nv);
		MH.init(mv);
		for(i=0;i+M<=N;i++) {
			if(NC[i]!=MC[0] || NC[i+M-1]!=MC[M-1]) continue;
			if(NL[i]<ML[0] || NL[i+M-1]<ML[M-1]) continue;
			auto nha = NH.hash(i+1,i+M-2);
			auto mha = MH.hash(1,M-2);
			if(nha==mha) ret++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}