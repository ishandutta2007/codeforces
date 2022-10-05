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
int E[505][505];
ll memo[505][505];
ll mo=1000000007;
ll memo2[505][505];



ll hoge2(int L,int R);
ll hoge(int L,int R) {
	if(L+1>=R) return 1;
	if(memo[L][R]>=0) return memo[L][R];
	ll ret=0;
	int pat=0;
	for(int m=R-1;m>L;m--) if(E[L][m]) {
		(ret+=hoge(m,R)*hoge2(L,m))%=mo;
	}
	return memo[L][R]=ret;
}

ll hoge2(int L,int R) {
	if(L+1==R) return 1;
	if(L>=R) return 0;
	if(memo2[L][R]>=0) return memo2[L][R];
	ll ret=0;
	for(int m=L;m<R;m++) {
		(ret+=hoge(L,m+1)*hoge(m+1,R+1))%=mo;
	}
	return memo2[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>E[y][x];
	MINUS(memo);
	MINUS(memo2);
	
	cout<<hoge(0,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}