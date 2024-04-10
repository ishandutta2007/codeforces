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

ll issq(ll V) {
	ll a=sqrt(V);
	for(ll b=a-2;b<=a+2;b++) if(b*b==V) return b;
	return 0;
}

unordered_map<ll,int> S[5];
map<ll,int> M,M2;
int N;
ll A[501];
ll mo=998244353;
int F[501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;;i++) {
		ll a=i;
		double b=i;
		a*=i;
		a*=i;
		b*=i;
		b*=i;
		if(b>3e18) break;
		S[3][a]=i;
		a*=i;
		b*=i;
		if(b<3e18) S[4][a]=i;
	}
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(S[4].count(A[i])) M[S[4][A[i]]]+=4;
		else if(S[3].count(A[i])) M[S[3][A[i]]]+=3;
		else if(issq(A[i])) M[issq(A[i])]+=2;
		else {
			F[i]=1;
		}
	}
	
	
	FOR(i,N) {
		FOR(j,N) if(F[i]) {
			ll g=__gcd(A[i],A[j]);
			if(1<g && g<A[i]) {
				F[i]=0;
				M[g]++;
				M[A[i]/g]++;
			}
		}
		if(F[i]) M2[A[i]]++;
	}
	
	ll ret=1;
	FORR(m,M) ret=ret*(m.second+1)%mo;
	FORR(m,M2) ret=ret*(m.second+1)*(m.second+1)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}