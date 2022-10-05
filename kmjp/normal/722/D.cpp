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

int N;
int Y[101010];
int X[101010];

int ok(int lim) {
	set<int> S;
	int i;
	FOR(i,N) {
		int x = Y[i];
		while(x>lim || S.count(x)) x/=2;
		if(x==0) return 0;
		X[i]=x;
		S.insert(X[i]);
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>Y[i];
	sort(Y,Y+N);
	reverse(Y,Y+N);
	int ret=1<<30;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	ok(ret);
	FOR(i,N) _P("%d%c",X[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}