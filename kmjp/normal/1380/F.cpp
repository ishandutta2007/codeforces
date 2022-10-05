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

const ll mo=998244353;

int N,M;
string S;
int X,D;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll pat[502020][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) {
		pat[1][i]=i+1;
		pat[2][i]=2*pat[1][i]+9-i;
		for(j=3;j<=501010;j++) pat[j][i]=(2*pat[j-1][i]+8*pat[j-2][i])%mo;
	}
	
	cin>>N>>M>>S;
	FORR(c,S) c-='0';
	
	
	set<int> C;
	C.insert(-1);
	ll ret=1;
	FOR(i,N) {
		C.insert(i);
		int s=i;
		while(i<N-1&&S[i]==1) i++;
		ret=ret*pat[i-s+1][S[i]]%mo;
	}
	C.insert(N);
	
	while(M--) {
		int X,D;
		cin>>X>>D;
		X--;
		if(S[X]!=D) {
			auto it=C.lower_bound(X+1);
			auto p=prev(it);
			if((S[X]!=1&&D!=1) || X==N-1) {
				ret=ret*modpow(pat[*it-*p][S[X]])%mo;
				ret=ret*pat[*it-*p][D]%mo;
				
			}
			else if(S[X]==1) {
				ret=ret*modpow(pat[*it-*p][S[*it-1]])%mo;
				ret=ret*pat[X+1-*p][D]%mo;
				ret=ret*pat[*it-(X+1)][S[*it-1]]%mo;
				C.insert(X+1);
				
			}
			else if(D==1) {
				auto n=next(it);
				x=*p;
				y=*n;
				ret=ret*modpow(pat[*it-x][S[*it-1]])%mo;
				ret=ret*modpow(pat[y-*it][S[y-1]])%mo;
				C.erase(X+1);
				ret=ret*pat[y-x][S[y-1]]%mo;
			}
			S[X]=D;
		}
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}