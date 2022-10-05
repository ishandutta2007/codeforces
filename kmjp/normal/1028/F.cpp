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

int Q,P;
unordered_map<ll,set<pair<ll,ll>>> M;
map<pair<ll,ll>,int> del;

pair<ll,ll> getpoint(ll x1,ll y1,ll x2,ll y2) {
	x1+=x2;
	y1+=y2;
	ll g=__gcd(x1,y1);
	return {x1/g,y1/g};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>j>>x>>y;
		if(j==1 || j==2) {
			ll t=1LL*x*x+1LL*y*y;
			if(j==1) {
				P++;
				M[t].insert({x,y});
				FORR(p,M[t]) {
					auto a=getpoint(p.first,p.second,x,y);
					del[a]++;
					if(p.first!=x || p.second!=y) del[a]++;
				}
			}
			else {
				P--;
				FORR(p,M[t]) {
					auto a=getpoint(p.first,p.second,x,y);
					del[a]--;
					if(p.first!=x || p.second!=y) del[a]--;
				}
				M[t].erase({x,y});
			}
		}
		else {
			int g=__gcd(x,y);
			x/=g;
			y/=g;
			cout<<P-del[{x,y}]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}