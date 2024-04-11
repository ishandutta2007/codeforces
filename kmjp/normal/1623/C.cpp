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

int T,N;
ll H[202020];
ll sum[202020];

int ok(ll v) {
	int i;
	FOR(i,N) sum[i]=0;
	for(i=N-1;i>=0;i--) {
		if(sum[i]+H[i]<v) return 0;
		ll a=min(H[i],sum[i]+H[i]-v)/3;
		if(i>=2) {
			sum[i-1]+=a;
			sum[i-2]+=2*a;
		}
	}
	return 1;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>H[i];
		ll ma=0;
		for(i=30;i>=0;i--) if(ok(ma+(1<<i))) ma+=1<<i;
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}