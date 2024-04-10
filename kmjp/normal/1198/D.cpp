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
string S[51];
int memo[51][51][51][51];
int SS[51][51];

int hoge(int L,int R,int T,int D) {
	if(memo[L][R][T][D]>=0) return memo[L][R][T][D];
	if(SS[D][R]-SS[T][R]-SS[D][L]+SS[T][L]==0) return memo[L][R][T][D]=0;
	int ret=max(D-T,R-L);
	
	int x,y;
	for(x=L+1;x<R;x++) ret=min(ret,hoge(L,x,T,D)+hoge(x,R,T,D));
	for(y=T+1;y<D;y++) ret=min(ret,hoge(L,R,T,y)+hoge(L,R,y,D));
	
	
	
	return memo[L][R][T][D]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) {
			SS[y+1][x+1]=SS[y][x+1]+SS[y+1][x]-SS[y][x]+(S[y][x]=='#');
		}
	}
	MINUS(memo);
	
	cout<<hoge(0,N,0,N)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}