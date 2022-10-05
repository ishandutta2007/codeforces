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
ll B[202020],C[202020],D[202020],S,R[202020];
ll one[32];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		if(B[i]>C[i]) return _P("-1\n");
		D[i]=B[i]+C[i];
		S+=D[i];
	}
	if(S%(2*N)!=0) return _P("-1\n");
	S /= (2*N);
	FOR(i,N) {
		if((D[i]-S)%N) return _P("-1\n");
		R[i]=(D[i]-S)/N;
		FOR(j,30) if(R[i]&(1<<j)) one[j]++;
	}
	FOR(i,N) {
		ll b=0,c=0;
		FOR(j,30) {
			if(R[i]&(1<<j)) {
				b+=one[j]<<j;
				c+=N<<j;
			}
			else {
				c+=one[j]<<j;
			}
		}
		if(b!=B[i] || c!=C[i]) return _P("-1\n");
	}
	FOR(i,N) _P("%d%c",(int)R[i],(i==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}