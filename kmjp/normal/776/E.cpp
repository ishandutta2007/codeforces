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

ll N,K;

ll F[2020];
ll G[2020];
ll mo=1000000007;
ll FF(ll v) {
	ll R=v;
	
	if(v<=2000) return F[v];
	
	for(ll a=2;a*a<=v;a++) {
		if(v%a==0) {
			R = R/a*(a-1);
			while(v%a==0) v/=a;
		}
	}
	if(v>1) R = R/v*(v-1);
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;i<=2000;i++) {
		for(j=1;j<i;j++) if(__gcd(i-j,j)==1) F[i]++;
		if(i==1) F[i]=1;
		for(j=1;j<=i;j++) if(i%j==0) G[i]+=F[j];
	}
	
	for(ll k=1;k<=K;k++) {
		if(N==1) break;
		if(k%2) N=FF(N);
	}
	cout<<N%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}