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

int A,B,K,T;
ll mo=1000000007;

int pat[4040];
ll from[430000];
ll to[430000];
ll sum[430002];

ll* FF=from+210000;
ll* SS=sum+210001;
ll* TT=to+210000;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>K>>T;
	
	FF[A-B]=1;
	
	while(T--) {
		ZERO(to);
		for(i=-203000;i<=203000;i++) SS[i]=SS[i-1]+FF[i];
		ll su=0;
		for(i=-201000;i<=201000;i++) {
			if(i==-201000) {
				for(x=-2*K;x<=2*K;x++) su += (2*K+1-abs(x))*FF[i+x];
				su %= mo;
			}
			else {
				su += SS[i+2*K]-SS[i-1];
				su -= SS[i-1]-SS[i-2*K-2];
				su = (su%mo+mo)%mo;
			}
			TT[i]=su;
		}
		swap(from,to);
	}
	ll ret=0;
	for(i=1;i<=201000;i++) ret += FF[i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}