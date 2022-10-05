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

int N,A;
int X[101010];

ll dist(ll x,ll a,ll b) {
	if(x<=a) return b-x;
	if(b<=x) return x-a;
	return min(b-a+b-x,b-a+x-a);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll mi=1LL<<60;
	
	cin>>N>>A;
	if(N==1) return _P("0\n");
	FOR(i,N) cin>>X[i];
	sort(X,X+N);
	mi=min(mi,dist(A,X[0],X[N-1]));
	mi=min(mi,dist(A,X[1],X[N-1]));
	mi=min(mi,dist(A,X[0],X[N-2]));
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}