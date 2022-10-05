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
int H,W;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		vector<ll> C;
		FOR(y,H) {
			cin>>s;
			ll v=0;
			FORR(c,s) v=v*2+(c-'0');
			C.push_back(v);
		}
		C.push_back(-1);
		C.push_back(1LL<<W);
		sort(ALL(C));
		ll num=(1LL<<W)-H;
		ll A=(num-1)/2+1;
		ll ret;
		FOR(i,C.size()) {
			ll d=C[i+1]-C[i]-1;
			if(A>d) {
				A-=d;
			}
			else {
				ret=C[i]+A;
				break;
			}
		}
		
		
		
		for(i=W-1;i>=0;i--) cout<<((ret>>i)%2);
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}