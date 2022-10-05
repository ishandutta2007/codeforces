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

int N,M;
const ll mo=998244353;
int X[1010101];

ll memo[501][501];

ll hoge(int L,int R) {
	if(L+1>=R) return 1;
	if(memo[L][R]>=0) return memo[L][R];
	int M=L;
	int i;
	for(i=L+1;i<R;i++) if(X[i]<X[M]) M=i;
	ll LS=0,RS=0;
	for(i=L;i<=M;i++) LS+=hoge(L,i)*hoge(i,M)%mo;
	for(i=M;i<R;i++) RS+=hoge(M+1,i+1)*hoge(i+1,R)%mo;
	LS%=mo;
	RS%=mo;
	return memo[L][R]=LS*RS%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>N>>M;
	FOR(i,M) cin>>X[i];
	
	cout<<hoge(0,N)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}