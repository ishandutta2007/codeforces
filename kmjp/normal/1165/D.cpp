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
int N;

ll issq(ll V) {
	if(V<0) return -1;
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> V(N);
		FOR(i,N) cin>>V[i];
		sort(ALL(V));
		ll x=1;
		FORR(v,V) {
			x=x/__gcd(x,v)*v;
			if(x>1LL<<40) break;
		}
		
		if(x>1LL<<40) {
			cout<<-1<<endl;
			continue;
		}
		if(x==V.back()) x*=V[0];
		
		int num=0;
		for(ll y=1;y*y<=x;y++) if(x%y==0) {
			num++;
			if(y*y!=x) num++;
		}
		if(num!=V.size()+2) {
			cout<<-1<<endl;
		}
		else {
			cout<<x<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}