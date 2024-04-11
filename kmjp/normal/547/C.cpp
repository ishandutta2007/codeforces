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

vector<ll> enumdiv(ll n) {
	vector<ll> V;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	return V;
}

int N,Q;
int A[202000];
int on[202000];
ll non;
int num[502000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	ll tot=0;
	
	while(Q--) {
		cin>>x;
		x--;
		
		vector<ll> V=enumdiv(A[x]);
		int bn=V.size();
		on[x]^=1;
		for(int mask=1;mask<1<<bn;mask++) {
			int odd=1;
			int n=1;
			FOR(i,bn) if(mask & (1<<i)) odd*=-1, n*=V[i];
			if(on[x]) {
				tot += odd*num[n];
				num[n]++;
			}
			else {
				tot -= odd*(--num[n]);
			}
		}
		
		if(on[x]) non++;
		else non--;
		cout<<non*(non-1)/2 + tot<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}