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
int A[1010101],ma=0;
ll S[1010101];
int P[1010101];
ll mo=1000000007;

ll F[1010101];
ll R[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i]);
		ma=max(ma,A[i]);
	}
	FOR(i,N-1) {
		scanf("%d",&P[i+1]);
		P[i+1]--;
	}
	
	for(i=N-1;i>=0;i--) {
		S[i]+=A[i];
		if(i) S[P[i]]+=S[i];
	}
	
	FOR(i,N) {
		ll a=S[0]/__gcd(S[i],S[0]);
		if(a<=N) F[a]++;
	}
	for(i=N;i>=1;i--) {
		for(j=i*2;j<=N;j+=i) F[j]+=F[i];
	}
	
	vector<ll> ret,hoge;
	for(i=N;i>=1;i--) if(F[i]==i) {
		ll a=1;
		FOR(j,hoge.size()) if(hoge[j]%i==0) a+=ret[j];
		hoge.push_back(i);
		ret.push_back(a%mo);
	}
	
	cout<<ret.back()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}