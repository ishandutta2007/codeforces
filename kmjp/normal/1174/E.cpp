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

ll mo=1000000007;
ll N;
const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll hoge(int cur,vector<int> V) {
	int sum=0;
	ll ret=1;
	FORR(v,V) {
		int n=N/cur-sum;
		ret=ret*comb(N-sum-1,n-1)%mo*fact[n]%mo;
		sum+=n;
		cur/=v;
	}
	ret=ret*fact[N-sum]%mo;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	comb(1,1);
	cin>>N;
	x=y=0;
	while(1<<(x+1) <= N) x++;
	while(3<<(y+1) <= N) y++;
	
	ll ret=0;
	vector<int> V;
	ll sum=0;
	FOR(i,x) V.push_back(2);
	ret+=hoge(1<<x,V);
	if(y+1==x) {
		V.clear();
		FOR(i,y) V.push_back(2);
		V.push_back(3);
		do {
			ret+=hoge(3<<y,V);
		} while(next_permutation(ALL(V)));
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}