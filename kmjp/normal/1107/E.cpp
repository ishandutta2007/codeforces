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
string S;
int A[1010];
ll dp[101][101][101][2];

ll hoge(int L,int R,int con,int num) {
	if(R<=L) return A[con];
	
	if(dp[L][R][con][num]>=0) return dp[L][R][con][num];
	
	ll ret=-1;
	//stop
	ret=A[con]+hoge(L+1,R,1,S[L]);
	if(con) {
		for(int i=L;i<R;i++) if(S[i]==num) {
			ret=max(ret,hoge(L,i,0,0)+hoge(i+1,R,con+1,num));
		}
	}
	return dp[L][R][con][num]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	cin>>N>>S;
	FORR(c,S) c-='0';
	FOR(i,N) cin>>A[i+1];
	cout<<hoge(0,N,0,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}