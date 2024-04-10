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

ll num(ll v) {
	ll ret=0;
	int i;
	FOR(i,61) {
		if((v<<i)>N) break;
		ll L=v<<i;
		ll R=((v+(v%2==0?2:1))<<i)-1;
		R=min(R,N);
		if(R>=L) ret+=R-L+1;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	ll ma1=1;
	for(i=60;i>=1;i--) if(num(ma1+(1LL<<i))>=K) ma1+=1LL<<i;
	ll ma2=0;
	for(i=60;i>=1;i--) if(num(ma2+(1LL<<i))>=K) ma2+=1LL<<i;
	cout<<max(ma1,ma2)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}