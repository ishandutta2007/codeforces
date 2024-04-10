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
ll H;
ll A[202020],B[202020];
vector<ll> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) cin>>A[i]>>B[i];
	A[N]=1LL<<60;
	FOR(i,N) {
		V.push_back(B[i]-A[i]);
		V.push_back(A[i+1]-B[i]);
	}
	ll ma=0;
	int L=0,R=1;
	ll TA=V[0],TB=0;
	for(L=0;L<2*N;L+=2) {
		while(TB+V[R]<H) TB+=V[R], TA+=V[R+1], R+=2;
		ma=max(ma,TA);
		TA-=V[L];
		TB-=V[L+1];
	}
	
	
	
	cout<<(ma+H)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}