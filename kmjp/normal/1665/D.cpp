#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T;
ll G;
ll ask(ll a,ll b) {
	cout<<"? "<<a<<" "<<b<<endl;
	if(G) {
		ll c=__gcd(G+a,G+b);
		return c;
	}
	else {
		cin>>a;
		return a;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ll X=0;
		ll a=1LL<<29;
		for(i=0;i<=28;i++) {
			ll b=a+(2LL<<i);
			ll c=ask(a,b);
			if(c%(2LL<<i)) {
				X+=1<<i;
				a-=1<<i;
			}
		}
		
		if(X+(1<<29)<=1000000000) {
			if(X<1<<29) {
				a=(1LL<<29)-X;
				ll b=a+(1LL<<30);
				ll c=ask(a,b);
				if(c%(1LL<<30)==0) {
					X+=1<<29;
				}
			}
			else {
				a=(1LL<<30)-X;
				ll b=a+(1LL<<30);
				ll c=ask(a,b);
				if(c%(1LL<<30)) {
					X+=1<<29;
				}
			}
		}
		
		cout<<"! "<<X<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}