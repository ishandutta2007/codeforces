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

ll N,A,R,M;
ll H[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>R>>M;
	M=min(M,A+R);
	FOR(i,N) cin>>H[i];
	sort(H,H+N);
	
	ll LS=0,RS=0;
	FOR(i,N) RS+=H[i];
	ll mi=1LL<<60;
	FOR(i,N) {
		RS-=H[i];
		ll add=1LL*H[i]*i-LS;
		ll rem=RS-1LL*H[i]*(N-1-i);
		if(add==rem) {
			mi=min(mi,add*M);
		}
		else if(add<rem) {
			mi=min(mi,add*M+(rem-add)*R);
		}
		else {
			mi=min(mi,rem*M+(add-rem)*A);
		}
		LS+=H[i];
	}
	for(ll v=max(0LL,LS/N-2);v<=max(0LL,LS/N+2);v++) {
		ll le=0,mo=0;
		FOR(i,N) {
			if(H[i]<v) le+=v-H[i];
			if(H[i]>v) mo+=H[i]-v;
		}
		
		if(le<=mo) mi=min(mi,le*M+(mo-le)*R);
		else mi=min(mi,mo*M+(le-mo)*A);
		
	}
	
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}