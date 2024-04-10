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
ll N;

ll hoge(ll v) {
	ll ret;
	if(v%4==0) ret=0;
	if(v%4==1) ret=2;
	if(v%4==2) ret=3;
	if(v%4==3) ret=1;
	
	if(v>=4) ret=hoge(v/4)*4+ret;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> S;
	/*
	x=1;
	FOR(i,30) {
		while(S.count(x)) x++;
		for(y=x+1;;y++) {
			if(S.count(y)) continue;
			if(S.count(x^y)) continue;
			break;
		}
		
		cout<<x<<" "<<y<<" "<<(x^y)<<endl;
		S.insert(x);
		S.insert(y);
		S.insert(x^y);
	}
	*/
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll P=(N-1)/3;
		ll Q=(N-1)%3;
		
		for(i=0;;i+=2) {
			if(P<1LL<<i) break;
			P-=(1LL<<i);
		}
		int step=i;
		ll X=1LL<<step;
		ll Y=1LL<<(step+1);
		
		ll a=X+P;
		ll b=Y+hoge(P);
		ll c=a^b;
		
		if(Q==0) cout<<a<<endl;
		if(Q==1) cout<<b<<endl;
		if(Q==2) cout<<c<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}