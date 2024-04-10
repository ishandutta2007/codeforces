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


int N,Q;
int V[101012];
ll sum[101020];
string S;
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	cin>>S;
	FOR(i,N) V[i+1]=V[i]+(S[i]=='1');
	
	ll v=1;
	for(i=1;i<=101010;i++) {
		sum[i]=(sum[i-1]+v)%mo;
		v=v*2%mo;
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		int n1=V[R]-V[L-1];
		int n0=R-L+1-n1;
		
		cout<<(sum[n0+n1]-sum[n0]+mo)%mo<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}