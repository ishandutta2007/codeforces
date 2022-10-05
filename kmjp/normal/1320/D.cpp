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
int Q;
int L[202020],R[202020],len[202020];

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
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
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
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

RollingHash RH,SS;
int del[202020];
int cur[202020];
int ne0[202020],pr0[202020];
string T,sing;

pair<ll,ll> gethash(int L,int len) {
	int R=L+len-1;
	pair<ll,ll> si=SS.hash(0,0);
	if(ne0[L]>R) {
		if(len%2==0) return {0,0};
		else return si;
	}
	
	int pr=0;
	if((ne0[L]-L)%2) pr=1;
	L=ne0[L];
	int po=0;
	if((R-pr0[R])%2) po=1;
	R=pr0[R];
	pair<ll,ll> ret=RH.hash(cur[L],cur[R]);
	if(pr) ret=RH.concat(si,ret,cur[R]-cur[L]+1);
	if(po) ret=RH.concat(ret,si,1);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	cin>>Q;
	x=0;
	FOR(i,N) {
		cur[i]=x;
		if(S[i]=='1'&&S[i+1]=='1') {
			del[i]=1;
			del[i+1]=2;
			cur[i+1]=x;
			i++;
		}
		else {
			x++;
			T.push_back(S[i]);
		}
	}
	cur[N]=x;
	x=-1;
	FOR(i,N) {
		if(S[i]=='0') x=i;
		pr0[i]=x;
	}
	x=N;
	for(i=N-1;i>=0;i--) {
		if(S[i]=='0') x=i;
		ne0[i]=x;
	}
	
	RH.init(T);
	sing="1";
	SS.init(sing);
	
	
	FOR(i,Q) {
		int L,R,len;
		cin>>L>>R>>len;
		if(gethash(L-1,len)==gethash(R-1,len)) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}