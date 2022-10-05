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

int N;
multiset<ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M.insert(x);
	}
	
	ll ret=1LL<<60;
	FOR(i,2) {
		multiset<ll> M2=M;
		ll tot=0;
		
		if(i==1 && M2.size()>=2) {
			ll a=*M2.begin();
			M2.erase(M2.begin());
			a+=*M2.begin();
			M2.erase(M2.begin());
			M2.insert(a);
			tot+=a;
		}
		
		while(M2.size()>2) {
			ll a=*M2.begin();
			M2.erase(M2.begin());
			a+=*M2.begin();
			M2.erase(M2.begin());
			a+=*M2.begin();
			M2.erase(M2.begin());
			tot+=a;
			M2.insert(a);
		}
		if(M2.size()==2) {
			tot+=*M2.begin();
			M2.erase(M2.begin());
			tot+=*M2.begin();
		}
		ret=min(ret,tot);
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}