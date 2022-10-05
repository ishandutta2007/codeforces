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

ll S,X,T;
ll ret;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X;
	
	T=S;
	
	ret=1;
	for(i=40;i>=0;i--) {
		if(X&(1LL<<i)) {
			S-=(1LL<<i);
			if(S<0) return _P("0\n");
			ret*=2;
		}
		else if(S>=(2LL<<i)) {
			S-=(2LL<<i);
		}
	}
	
	
	if(S) {
		cout<<0<<endl;
	}
	else {
		if(T==X) ret-=2;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}