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
ll X;
ll D[602020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>D[i];
	reverse(D,D+N);
	ll ma=0;
	ll S=0,T=0;
	for(int L=0,R=0;L<N;L++) {
		while(S+D[R%N]<=X) {
			S+=D[R%N];
			T+=D[R%N]*(D[R%N]+1)/2;
			R++;
		}
		
		ll cur=T+(D[R%N]+D[R%N]-(X-S-1))*(X-S)/2;
		ma=max(ma,cur);
		S-=D[L];
		T-=D[L]*(D[L]+1)/2;
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}