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

ll dp[505][505];

ll hoge(int L,int R) {
	if(L+1==R) return 0;
	if(L+2==R) return L*(L+1)*(L+2);
	if(dp[L][R]>=0) return dp[L][R];
	
	ll mi=1LL<<60;
	int i;
	for(i=L+1;i<=R-1;i++) mi=min(mi,L*i*R+hoge(L,i)+hoge(i,R));
	
	return dp[L][R]=mi;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	MINUS(dp);
	
	ll mi=1LL<<60;
	for(i=2;i<N;i++) mi=min(mi,1*N*i+hoge(1,i)+hoge(i,N));
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}