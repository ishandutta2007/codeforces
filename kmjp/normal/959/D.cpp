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
int A[101010];
int B[101010];
int did[3000000];
const int prime_max = 3000000;
int NP,prime[300000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

set<int> enumpr(ll n) {
	set<int> V;
	
	while(divp[n]>1) {
		V.insert(divp[n]);
		n/=divp[n];
	}
	if(n>1) V.insert(n);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	int ng=0;
	int prev=0;
	FOR(i,N) {
		if(ng==0) {
			set<int> V=enumpr(A[i]);
			FORR(v,V) if(did[v]) ng=1;
			
			if(ng==0) {
				B[i]=A[i];
				FORR(v,V) did[v]=1;
			}
			else {
				ng=1;
				B[i]=A[i]+1;
				while(1) {
					set<int> V=enumpr(B[i]);
					int ok=1;
					FORR(v,V) if(did[v]) ok=0;
					if(ok==0) {
						B[i]++;
						continue;
					}
					FORR(v,V) did[v]=1;
					break;
				}
			}
		}
		else {
			while(did[prime[prev]]==1) prev++;
			B[i]=prime[prev];
			did[prime[prev]]=1;
		}
		cout<<B[i]<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}