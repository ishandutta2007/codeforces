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
	/*ll*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		ll a =(hash_[0][r+1]-hash_[0][l]*pmo[0][r+1-l])%mo0;
		ll b= (hash_[1][r+1]-hash_[1][l]*pmo[1][r+1-l])%mo1;
		if(a<0) a+=mo0;
		if(b<0) b+=mo1;
		return (a<<32) |  b;
	}
	ll hash(string s) { init(s); return hash(0,s.size()-1); }
	static ll concat(ll L ,ll R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		ll La=L>>32,Lb=(L<<32)>>32,Ra=R>>32,Rb=(R<<32)>>32;
		return (((Ra + La*pmo[0][RL])%mo0)<<32)|((Rb + Lb*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash rh[27];

string S[27];
int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>S[0];
	FOR(i,26) {
		S[i+1]=S[0];
		FORR(c,S[i+1]) c=c=='a'+i;
		rh[i].init(S[i+1]);
	}
	
	while(M--) {
		cin>>x>>y>>l;
		vector<ll> A[2];
		FOR(i,26) {
			A[0].push_back(rh[i].hash(x-1,x-1+l-1));
			A[1].push_back(rh[i].hash(y-1,y-1+l-1));
		}
		sort(ALL(A[0]));
		sort(ALL(A[1]));
		if(A[0]==A[1]) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}