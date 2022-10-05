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
ll K;
ll V[1010101];
ll T[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%" PRId64, &N,&K);
	FOR(i,N-1) {
		scanf("%d%" PRId64, &x,&V[i+1]);
		V[i+1]^=V[x-1];
	}
	sort(V,V+N);
	
	ll ret=0;
	for(i=61;i>=0;i--) {
		FOR(j,N) T[j]=(V[j]^ret)>>i;
		sort(T,T+N);
		
		int L=0,R=0;
		ll sum=0;
		FOR(j,N) {
			ll v=V[j]>>i;
			while(L<N&&T[L]<v) L++;
			while(R<N&&T[R]<=v) R++;
			sum+=R-L;
		}
		
		if(sum<K) {
			K-=sum;
			ret^=1LL<<i;
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}