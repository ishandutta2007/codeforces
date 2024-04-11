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
int cnt[72];

ll mo=1000000007;
ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

const int prime_max = 71;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

ll from[1<<19];
ll to[1<<19];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		cnt[x]++;
	}
	
	from[0]=1;
	for(i=1;i<=70;i++) {
		ll p[2]={};
		for(x=0;x<=cnt[i];x++) (p[x%2]+=combi(cnt[i],x))%=mo;
		int mask=0,cmask;
		x=i;
		FOR(j,NP) {
			while(x%prime[j]==0) x/=prime[j], mask^=1<<j;
		}
		ZERO(to);
		FOR(cmask,1<<NP) {
			(to[cmask] += from[cmask]*p[0])%=mo;
			(to[cmask] += from[cmask^mask]*p[1])%=mo;
		}
		
		swap(from,to);
	}
	cout<<(from[0]+mo-1)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}