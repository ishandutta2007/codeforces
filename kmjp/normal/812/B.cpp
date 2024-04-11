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

int H,W;
int L[20],R[20];
int dp[20][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	W+=2;
	int last=-1;
	FOR(y,H) {
		cin>>s;
		L[H-1-y]=R[H-1-y]=-1;
		FOR(x,W) if(s[x]=='1') {
			if(L[H-1-y]==-1) L[H-1-y]=x;
			R[H-1-y]=x;
		}
		if(L[H-1-y]>=0) last=max(H-1-y,last);
	}
	
	if(last==-1) return _P("0\n");
	if(last==0) return _P("%d\n",R[0]);
	
	if(L[0]==-1) {
		dp[0][0]=0;
		dp[0][1]=W-1;
	}
	else {
		dp[0][0]=R[0]*2;
		dp[0][1]=W-1;
	}
	for(y=1;y<last;y++) {
		dp[y][0]=min(dp[y-1][0]+1+((L[y]==-1)?0:R[y]*2),dp[y-1][1]+1+(W-1));
		dp[y][1]=min(dp[y-1][1]+1+((L[y]==-1)?0:(W-1-L[y])*2),dp[y-1][0]+1+(W-1));
	}
	int ret=min(dp[y-1][0]+1+R[y],dp[y-1][1]+1+(W-1-L[y]));
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}