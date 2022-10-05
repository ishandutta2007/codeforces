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

ll N,K;
ll fib[60];
int p[55];
int ret[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fib[0]=fib[1]=1;
	for(i=2;i<=50;i++) fib[i]=fib[i-1]+fib[i-2];
	
	cin>>N>>K;
	K--;
	
	FOR(i,N) p[i]=i+1;
	FOR(i,N-1) if(K>=fib[N-i-1]) {
		K-=fib[N-i-1];
		swap(p[i],p[i+1]);
		i++;
	}
	
	FOR(i,N) _P("%d ",p[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}