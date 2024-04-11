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
int C[505];
int memo[505][505];

int hoge(int L,int R) {
	if(L>R) return 0;
	if(L==R) return 1;
	if(memo[L][R]>=0) return memo[L][R];
	int ret=1000;
	
	if(C[L]==C[R]) {
		if(L+1==R) ret=1;
		else ret=hoge(L+1,R-1);
	}
	for(int i=L;i<R;i++) ret=min(ret,hoge(L,i)+hoge(i+1,R));
	
	return memo[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	MINUS(memo);
	_P("%d\n",hoge(0,N-1));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}