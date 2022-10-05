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
ll K,S,T;
ll C[202020],V[202020];
ll G[202020],GS[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S>>T;
	
	FOR(i,N) cin>>C[i]>>V[i];
	x=0;
	FOR(i,K) cin>>G[i];
	G[K]=S;
	K++;
	sort(G,G+K);
	for(i=K-1;i>=1;i--) G[i]-=G[i-1];
	
	sort(G,G+K);
	FOR(i,K) GS[i+1]=GS[i]+G[i];
	
	int mi=1<<30;
	FOR(i,N) if(mi>C[i] && V[i]>=G[K-1]) {
		x = lower_bound(G,G+K,V[i]/2+1)-G;
		
		ll t=S+(2*(GS[K]-GS[x])-(K-x)*V[i]);
		if(t<=T) mi=C[i];
		
	}
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}