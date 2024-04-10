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
ll A[202020];

const int prime_max = 1000000;
vector<int> prime;
int NP;
int divp[prime_max+1];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}
vector<pair<ll,int>> V;
ll mi;
set<ll> D;

void hoge(ll tar) {
	ll sum=0;
	if(tar==1 || D.count(tar)) return;
	D.insert(tar);
	FORR(v,V) {
		ll dif=min(v.first%tar,tar-v.first%tar);
		if(v.first<tar) dif=tar-v.first%tar;
		sum+=dif*v.second;
		if(sum>=mi) return;
	}
	mi=min(mi,sum);
}

void check(ll v) {
	int i;
	FOR(i,NP) {
		if(1LL*prime[i]*prime[i]>v) break;
		if(v%prime[i]==0) {
			hoge(prime[i]);
			while(v%prime[i]==0) v/=prime[i];
		}
	}
	hoge(v);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) {
		if(V.empty()||V.back().first!=A[i]) V.push_back({A[i],0});
		V.back().second++;
	}
	cprime();
	mi=N;
	srand(time(NULL));
	FOR(i,100) {
		x=(1LL*rand()*rand()+rand()+i*i)%N;
		check(A[x]);
		check(A[x]+1);
		check(max(1LL,A[x]-1));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}