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

ll N,P,W,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>W>>D;
	ll a=P/W;
	
	FOR(i,200000) if(a-i>=0) {
		ll X=a-i;
		ll P2=P-X*W;
		if(X>=0 && P2%D==0) {
			ll Y=P2/D;
			if(Y>=0 && X+Y<=N) {
				cout<<X<<" "<<Y<<" "<<(N-X-Y)<<endl;
				return;
			}
		}
	}
	
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}