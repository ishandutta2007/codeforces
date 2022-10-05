#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int mo=1000000007;

const int prime_max = 1000001;
int NP,prime[100000],divp[prime_max],id[1010100];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		id[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int N,Q;
int A[202020];
ll P[202020],PR[202020];
vector<int> di[202020];

int L[202020],R[202020],ret[202020];;

vector<pair<int,int> > pre[202020],nex[202020];
vector<pair<int,int> > QQ[2505];
int rev[1202020],revp[1202020];
int num[82020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	for(i=2;i<=1000000;i++) if(divp[i]==0) {
		rev[i]=(i-1)*1LL*modpow(i) % mo;
		revp[i]=modpow(rev[i]) % mo;
	}
	
	cin>>N;
	P[0]=PR[0]=1;
	FOR(i,N) {
		cin>>A[i];
		P[i+1]=P[i]*A[i]%mo;
		PR[i+1]=modpow(P[i+1]);
		x=A[i];
		while(divp[x]) di[i].push_back(divp[x]), x/=divp[x];
		if(x>1) di[i].push_back(x);
		sort(ALL(di[i]));
		di[i].erase(unique(ALL(di[i])),di[i].end());
	}
	
	ZERO(num);
	FOR(i,N) {
		FORR(r,di[i]) pre[i+1].push_back({num[id[r]],r}), num[id[r]]=i+1;
		sort(ALL(pre[i+1]));
	}
	FOR(i,NP+1) num[i]=N+1;
	for(i=N-1;i>=0;i--) {
		FORR(r,di[i]) nex[i+1].push_back({num[id[r]],r}), num[id[r]]=i+1;
		sort(ALL(nex[i+1]));
		reverse(ALL(nex[i+1]));
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		QQ[L[i]/600].push_back({R[i],i});
	}
	
	FOR(i,400) {
		ll pat=1;
		int LL=1,RR=0;
		sort(ALL(QQ[i]));
		FORR(r,QQ[i]) {
			x=r.first;
			y=r.second;
			
			while(RR<x) {
				RR++;
				FORR(rr,pre[RR]) {
					if(rr.first>=LL) break;
					(pat *= rev[rr.second])%=mo;
				}
			}
			while(LL<L[y]) {
				FORR(rr,nex[LL]) {
					if(rr.first<=RR) break;
					(pat *= revp[rr.second])%=mo;
				}
				LL++;
			}
			while(LL>L[y]) {
				LL--;
				FORR(rr,nex[LL]) {
					if(rr.first<=RR) break;
					(pat *= rev[rr.second])%=mo;
				}
			}
			ret[y]=P[RR]*PR[LL-1]%mo*pat%mo;
		}
	}
	FOR(i,Q) _P("%d\n",ret[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}