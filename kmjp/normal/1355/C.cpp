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

ll A,B,C,D;

ll hoge(ll x,ll y,ll U) {
	
	ll ret=0;
	if(y<=U) {
		ret+=(y-x+1)*(x+1+y+1)/2;
	}
	else if(x<U) {
		ll d=y-U;
		ret+=(y-x+1)*(x+1+y+1)/2;
		ret-=d*(d+1)/2;
	}
	else {
		ret+=(y-x+1)*(U+1);
	}
	return ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	ll ret=0;
	for(y=B;y<=C;y++) {
		ret+=hoge(y+A-1,y+B-1,D);
		ret-=hoge(y+A-1,y+B-1,C-1);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}