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

ll N;

void go(ll a,ll b) {
	cout<<a<<" "<<b<<endl;
	exit(0);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	if(N==0) go(0,0);
	
	ll st=(1<<30)-1;
	for(i=29;i>=0;i--) {
		ll nst=st-(1<<i);
		if(N<=3*nst*(nst+1)) st=nst;
	}
	N -= 3*(st-1)*st;
	if(N<=st) go(2*st-N,2*N);
	N-=st;
	if(N<=st) go(st-2*N,2*st);
	N-=st;
	if(N<=st) go(-st-N,2*st-2*N);
	N-=st;
	if(N<=st) go(-2*st+N,-2*N);
	N-=st;
	if(N<=st) go(-st+2*N,-2*st);
	N-=st;
	return go(st+N,-2*st+2*N);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}