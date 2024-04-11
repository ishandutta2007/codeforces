#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
string S[2];
int R[2][202020];
int dp[2][2][2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>S[0]>>S[1];
	N+=2;
	S[0]+="00";
	S[1]+="00";
	
	R[0][N]=R[1][N]=N+2;
	R[0][N+1]=R[1][N+1]=N+2;
	int total=0;
	for(i=N-1;i>=0;i--) {
		FOR(j,2) {
			R[j][i]=R[j][i+1];
			if(S[j][i]=='1') {
				R[j][i]=i;
				total++;
			}
		}
	}
	FOR(i,N) FOR(x,2) FOR(y,2) FOR(k,2) dp[x][y][k][i]=1<<30;
	dp[0][0][0][0]=0;
	int ret=1<<30;
	FOR(x,N) {
		FOR(i,2) FOR(k,2) FOR(y,2) {
			int sx=R[y][x+1];
			int sx2=R[y^1][x+i];
			if(k) sx2=R[y^1][x+2];
			int cur=dp[y][i][k][x];
			if(cur>=1<<29) continue;
				
			if(sx>N&&sx2>N) {
				ret=min(ret,cur);
			}
			else {
				if(sx<=sx2) {
					chmin(dp[y][(sx==x+1)&&k][0][sx],cur);
				}
				else if(sx2+1==sx) {
					// same line
					chmin(dp[y][(sx==x+1)&&k][0][sx],cur+1);
					// other line
					chmin(dp[y^1][sx2==x][1][sx2],cur+1);
				}
				else {
					chmin(dp[y^1][sx2==x][0][sx2],cur);
					chmin(dp[y][1][0][sx2],cur+1);
				}
			}
		}
	}
	cout<<total-ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}