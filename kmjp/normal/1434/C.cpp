#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
ll A,B,C,D;

ll hoge(ll t) {
	ll dam=t*A;
	__int128_t sum=t*(t-1)/2;
	sum*=B*D;
	
	if(sum>dam) return -1;
	return dam-sum;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D;
		
		if(B*C<A) {
			cout<<-1<<endl;
			continue;
		}
		if(C<=D) {
			cout<<A<<endl;
			continue;
		}
		// num attack
		ll att=(C-1)/D;
		ll L=1,R=att+1;
		ll ma=0;
		while(R-L>2) {
			ll m1=(2*L+R)/3;
			ll m2=(2*R+L)/3;
			ll v1=hoge(m1);
			ll v2=hoge(m2);
			ma=max({ma,v1,v2});
			if(v1==-1) {
				R=m1;
			}
			else {
				if(v1<=v2) L=m1;
				if(v2<=v1) R=m2;
			}
		}
		for(i=L;i<=R;i++) ma=max(ma,hoge(i));
		
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}