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

int N,M;
ll X[303030],P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll g=0;
	FOR(i,N) {
		cin>>X[i];
		if(i) g=__gcd(g,X[i]-X[i-1]);
	}
	FOR(i,M) {
		cin>>P[i];
		if(g%P[i]==0) {
			cout<<"YES"<<endl;
			cout<<X[0]<<" "<<(i+1)<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}