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
int X,P,K;
vector<int> ps;

vector<int> enumpr(int n) {
	vector<int> V;
	for(int i=2;i*i<=n;i++) if(n%i==0) {
		V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	sort(V.begin(),V.end());
	return V;
}

ll count(ll a,vector<int>& ps) {
	ll ret=0;
	int n=ps.size(),mask,i;
	FOR(mask,1<<n) {
		int s=1,sg=1;
		FOR(i,n) if(mask&(1<<i)) s*=ps[i], sg=-sg;
		ret+=sg*(a/s);
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>P>>K;
		ps=enumpr(P);
		K+=count(X,ps);
		ll ret=1LL<<62;
		for(i=61;i>=0;i--) if(count(ret-(1LL<<i),ps)>=K) ret-=1LL<<i;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}