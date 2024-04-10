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
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i]*(mul1-2))%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i]*(mul0-3))%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	pair<ll,ll> hash(string s) { init(s); return hash(0,s.size()-1); }
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;
RollingHash rh;

int N;
string S[303],T;
int A[303],B[303],L[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int tot=0;
	cin>>N;
	tot+=N-1;
	FOR(i,N) {
		cin>>S[i];
		T+=S[i]+"$";
		L[i]=S[i].size()+1;
		B[i]=A[i]+L[i]-1;
		A[i+1]=B[i]+1;
		tot+=L[i]-1;
	}
	
	rh.init(T);
	int ret=tot;
	FOR(x,N) {
		for(int len=1;x+len<=N;len++) {
			int del=B[x+len-1]-A[x]-len;
			
			int num=0;
			for(y=x;y+len<=N;y++) {
				if(rh.hash(A[x],B[x+len-1])==rh.hash(A[y],B[y+len-1])) {
					num+=del;
					y+=len-1;
				}
			}
			if(num>del) ret=min(ret,tot-num);
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}