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

ll X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	ll Y=X;
	vector<ll> V;
	for(ll a=2;a*a<=X;a++) if(X%a==0) {
		V.push_back(1);
		while(X%a==0) {
			V.back()*=a;
			X/=a;
		}
	}
	if(X>1) V.push_back(X);
	
	ll mi=Y;
	int mask;
	FOR(mask,1<<V.size()) {
		ll a=1;
		FOR(i,V.size()) if(mask&(1<<i)) a*=V[i];
		mi=min(mi,max(a,Y/a));
	}
	
	
	cout<<Y/mi<<" "<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}