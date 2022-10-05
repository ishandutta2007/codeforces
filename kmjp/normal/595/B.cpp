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

int N,K;
ll mo=1000000007;
ll A[101010],B[101010];

ll dodo(ll a,ll b,ll k) {
	ll t=1;
	while(k-->1) t*=10;
	if(b==0) {
		return (t*10-1)/a - (t-1)/a;
	}
	else {
		return 1+(t*10-1)/a - (t*(b+1)-1)/a + (t*b-1)/a;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N/K) cin>>A[i];
	FOR(i,N/K) cin>>B[i];
	ll pat=1;
	FOR(i,N/K) (pat*=dodo(A[i],B[i],K))%=mo;
	cout<<pat<<endl;;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}