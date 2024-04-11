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

int N,M;
int A[50050],X[50500];
int L[50050],R[50500];

int XX[1010101];
int ma[50505];
int ret[50505];

ll xorxor(ll val) {
	int i;
	ll ret=((val+1)/2)%2;
	for(i=0;i<=29;i++) if((val>>i)%2) ret |= (1^(val%2))<<i;
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) XX[i]=XX[i-1]^i;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i], X[i]=XX[A[i]];
	FOR(i,M) cin>>L[i]>>R[i], L[i]--,R[i]--;
	
	FOR(x,N) {
		ma[x-1]=0;
		for(y=x;y<N;y++) ma[y]=max(ma[y-1],X[x]^X[y]^((A[x]>A[y])?A[y]:A[x]));
		FOR(i,M) if(L[i]<=x) ret[i]=max(ret[i],ma[R[i]]);
	}
	
	FOR(i,M) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}