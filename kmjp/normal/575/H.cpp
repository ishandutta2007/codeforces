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

ll N;
ll ret=0;
ll mo=1000000007;

ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll fact[2020200];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	fact[0]=1;
	for(i=1;i<=2*N+2;i++) fact[i]=fact[i-1]*i%mo;
	
	cout<<(mo-1+fact[2*N+2]*rev(fact[N+1])%mo*rev(fact[N+1]))%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}