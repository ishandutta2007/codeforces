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

const int prime_max = 1100001;
vector<int> prime;
int NP,divp[prime_max];
ll chash[prime_max];
ll FS[prime_max];
unordered_map<ll,int> rev;
int N;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

std::random_device rnd;     // 
std::mt19937 mt(rnd());            // 32

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cprime();

	ll th=0;
	for(i=2;i<=N;i++) {
		chash[i]=((1LL*mt())<<31)+mt()+i;
		FS[i]=FS[i-1];
		x=i;
		while(x>1) {
			FS[i]^=chash[divp[x]];
			x/=divp[x];
		}
		th^=FS[i];
		rev[FS[i]]=i;
	}
	
	vector<int> exc;
	
	if(th==0) {
		exc={};
	}
	else if(rev.count(th)) {
		exc={rev[th]};
	}
	else {
		rev.clear();
		for(i=2;i<=N;i++) {
			ll tmp=th^FS[i];
			if(rev.count(tmp)) {
				exc={rev[tmp],i};
			}
			rev[FS[i]]=i;
		}
		if(exc.empty()) {
			exc={2,N,N/2};
		}
	}
	
	cout<<N-(exc.size())<<endl;
	ll tc=0;
	for(i=1;i<=N;i++) {
		if(count(ALL(exc),i)==0) {
			cout<<i<<" ";
			tc^=FS[i];
		}
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}