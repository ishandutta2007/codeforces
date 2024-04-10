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
ll A[1010101];
ll S;
ll mi=1LL<<60;

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

ll hoge(ll cand) {
	int i;
	if(cand==1) return 1LL<<60;
	ll ret=0;
	ll sum=0;
	vector<pair<ll,ll>> V;
	FOR(i,N) {
		ll C=A[i];
		ll add=min(C,cand-sum);
		if(add) {
			V.push_back({i,add});
			C-=add;
			sum+=add;
			
			if(sum==cand) {
				ll vc=(cand+1)/2;
				ll mid=0;
				FORR(a,V) {
					if(vc>0 && a.second>=vc) mid=a.first;
					vc-=a.second;
				}
				FORR(a,V) {
					ret+=abs(a.first-mid)*a.second;
				}
				V.clear();
				sum=0;
			}
		}
		
		C%=cand;
		if(C) {
			V.push_back({i,C});
			sum+=C;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i]);
		S+=A[i];
	}
	
	cprime();
	mi=hoge(S);
	FOR(i,NP) if(S%prime[i]==0) mi=min(mi,hoge(prime[i]));
	for(ll a=1;a*a<=S;a++) if(S%a==0 && S/a>=1000000 && isprime(S/a)) mi=min(mi,hoge(S/a));
	
	if(mi==1LL<<60) return _P("-1\n");
	
	cout<<mi<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}