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
int K[101];
int L[101][101],R[101][101];
int T[101][101];

int memo[101][101];

int hoge(int LL,int RR) {
	if(LL>RR) return 0;
	if(memo[LL][RR]>=0) return memo[LL][RR];
	int ret=0;
	int i;
	for(int x=LL;x<=RR;x++) {
		int num=0;
		FOR(i,N) {
			int t=T[i][x];
			if(L[i][t]>=LL&&R[i][t]<=RR) num++;
		}
		ret=max(ret,num*num+hoge(LL,x-1)+hoge(x+1,RR));
	}
	
	
	return memo[LL][RR]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>K[i];
		FOR(j,K[i]) {
			cin>>x>>y;
			L[i][j]=x-1;
			R[i][j]=y-1;
			for(k=L[i][j];k<=R[i][j];k++) T[i][k]=j;
		}
	}
	
	MINUS(memo);
	cout<<hoge(0,M-1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}