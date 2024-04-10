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

int A;
string S,T;
int X,Y;

int dp[404][404];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	while(A--) {
		cin>>S>>T;
		X=S.size();
		Y=T.size();
		MINUS(dp);
		for(i=1;i<=Y;i++) dp[0][i]=i;
		FORR(c,S) {
			for(x=X;x>=0;x--) for(y=X;y>=0;y--) if(dp[x][y]!=-1) {
				if(x!=y && x!=X && c==T[x]) dp[x+1][y]=max(dp[x+1][y],dp[x][y]);
				if(dp[x][y]!=X && c==T[dp[x][y]]) dp[x][y]++;
			}
		}
		int ok=0;
		FOR(i,Y+1) if(dp[i][i]==Y) ok=1;
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}