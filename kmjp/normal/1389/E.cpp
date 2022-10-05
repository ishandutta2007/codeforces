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


int T;
ll M,D,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M>>D>>W;
		
		if(D==1) {
			cout<<0<<endl;
			continue;
		}
		ll G=__gcd(W,D-1);
		
		W/=G;
		
		ll ret=0;
		x=min(M,D)-1;
		
		if((x+1)%W==0) {
			ll a=(x+1)/W;
			ret=a*(a-1)/2*W;
		}
		else {
			ll a=(x+1)/W;
			ll m=(x+1)%W;
			ret=a*(a+1)/2*m+a*(a-1)/2*(W-m);
		}
		
		
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}