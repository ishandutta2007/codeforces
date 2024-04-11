#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll X;
vector<pair<ll,ll> > V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	for(ll H=1;H<1601010;H++) {
		ll a = H*(H+1)/2;
		ll b = -H*(H-1)*(H+1)/6;
		if(X-b<=0) continue;
		if((X-b)%a) continue;
		ll W = (X-b)/a;
		
		if(H<=W) V.push_back({H,W});
		if(H<W) V.push_back({W,H});
	}
	sort(ALL(V));
	cout<<V.size()<<endl;
	FORR(r,V) cout<<r.first<<" "<<r.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}