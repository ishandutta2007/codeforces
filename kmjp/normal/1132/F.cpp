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

int memo[505][505];

int hoge(int L,int R) {
	if(L>=R) return 0;
	if(memo[L][R]>=0) return memo[L][R];
	
	int ret=1010101;
	ret=1+hoge(L+1,R);
	for(int ne=L+1;ne<R;ne++) if(S[L]==S[ne]) {
		ret=min(ret,hoge(ne,R)+hoge(L+1,ne));
	}
	
	
	return memo[L][R]=ret;
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	MINUS(memo);
	
	cout<<hoge(0,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}