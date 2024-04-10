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

ll X,Y,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>K;
	
	if(2*X*Y%K) return _P("NO\n");
	ll A=X,B=Y;
	ll g=__gcd(A,K);
	A/=g;
	K/=g;
	g=__gcd(B,K);
	B/=g;
	K/=g;
	
	if(K==1) {
		if(2*A<=X) A*=2;
		else B*=2;
	}
	
	
	cout<<"YES"<<endl;
	cout<<0<<" "<<0<<endl;
	cout<<A<<" "<<0<<endl;
	cout<<0<<" "<<B<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}