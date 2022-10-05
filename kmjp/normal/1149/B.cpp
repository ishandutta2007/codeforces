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

int N,Q;
int nex[101010][26];
string S;
int dp[252][252][252];
string T[3];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	cin>>S;
	FOR(i,26) nex[N+1][i]=N+1;
	FOR(i,26) nex[N][i]=N+1;
	for(i=N-1;i>=0;i--) {
		FOR(j,26) nex[i][j]=nex[i+1][j];
		nex[i][S[i]-'a']=i+1;
	}
	
	FOR(i,252) FOR(j,252) FOR(k,252) dp[i][j][k]=N+1;
	dp[0][0][0]=0;
	while(Q--) {
		cin>>s>>i;
		i--;
		int a=T[0].size(),b=T[1].size(),c=T[2].size();
		if(s=="+") {
			cin>>s;
			
			if(i==0) {
				FOR(x,b+1) FOR(y,c+1) {
					if(x<b) dp[a][x+1][y]=min(dp[a][x+1][y],nex[dp[a][x][y]][T[1][x]-'a']);
					if(y<c) dp[a][x][y+1]=min(dp[a][x][y+1],nex[dp[a][x][y]][T[2][y]-'a']);
					dp[a+1][x][y]=min(dp[a+1][x][y],nex[dp[a][x][y]][s[0]-'a']);
					if(x<b) dp[a+1][x+1][y]=min(dp[a+1][x+1][y],nex[dp[a+1][x][y]][T[1][x]-'a']);
					if(y<c) dp[a+1][x][y+1]=min(dp[a+1][x][y+1],nex[dp[a+1][x][y]][T[2][y]-'a']);
				}
				T[0].push_back(s[0]);
			}
			else if(i==1) {
				FOR(x,a+1) FOR(y,c+1) {
					if(x<a) dp[x+1][b][y]=min(dp[x+1][b][y],nex[dp[x][b][y]][T[0][x]-'a']);
					if(y<c) dp[x][b][y+1]=min(dp[x][b][y+1],nex[dp[x][b][y]][T[2][y]-'a']);
					dp[x][b+1][y]=min(dp[x][b+1][y],nex[dp[x][b][y]][s[0]-'a']);
					if(x<a) dp[x+1][b+1][y]=min(dp[x+1][b+1][y],nex[dp[x][b+1][y]][T[0][x]-'a']);
					if(y<c) dp[x][b+1][y+1]=min(dp[x][b+1][y+1],nex[dp[x][b+1][y]][T[2][y]-'a']);
				}
				T[1].push_back(s[0]);
			}
			else {
				FOR(x,a+1) FOR(y,b+1) {
					if(x<a) dp[x+1][y][c]=min(dp[x+1][y][c],nex[dp[x][y][c]][T[0][x]-'a']);
					if(y<b) dp[x][y+1][c]=min(dp[x][y+1][c],nex[dp[x][y][c]][T[1][y]-'a']);
					dp[x][y][c+1]=min(dp[x][y][c+1],nex[dp[x][y][c]][s[0]-'a']);
					if(x<a) dp[x+1][y][c+1]=min(dp[x+1][y][c+1],nex[dp[x][y][c+1]][T[0][x]-'a']);
					if(y<b) dp[x][y+1][c+1]=min(dp[x][y+1][c+1],nex[dp[x][y][c+1]][T[1][y]-'a']);
				}
				T[2].push_back(s[0]);
			}
		}
		else {
			if(i==0) {
				FOR(x,252) FOR(y,252) dp[a][x][y]=N+1;
			}
			if(i==1) {
				FOR(x,252) FOR(y,252) dp[x][b][y]=N+1;
			}
			if(i==2) {
				FOR(x,252) FOR(y,252) dp[x][y][c]=N+1;
			}
			
			T[i].pop_back();
		}
		if(dp[T[0].size()][T[1].size()][T[2].size()]<=N) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}