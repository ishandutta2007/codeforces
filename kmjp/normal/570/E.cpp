#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string A[505];
ll mo=1000000007;
ll dp[2][505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int x1,x2,y1,y2;
	
	cin>>H>>W;
	FOR(y,H) cin>>A[y];
	
	dp[0][0][W-1]=A[0][0]==A[H-1][W-1];
	FOR(i,(H+W-2)/2) {
		int cur=i%2,tar=cur^1;
		ZERO(dp[tar]);
		FOR(x1,W) {
			y1=i-x1;
			if(y1<0 || y1>=H) continue;
			for(x2=x1;x2<W;x2++) {
				y2=H-1-(i-(W-1-x2));
				if(y2<0 || y2>=H || y1>y2) continue;
				if(dp[cur][x1][x2]==0) continue;
				FOR(j,4) {
					int nx1=x1,ny1=y1,nx2=x2,ny2=y2;
					if(j%2) nx1++;
					else ny1++;
					if(j/2) nx2--;
					else ny2--;
					if(nx1<=nx2 && ny1<=ny2 && A[ny1][nx1]==A[ny2][nx2]) (dp[tar][nx1][nx2]+=dp[cur][x1][x2])%=mo;
				}
			}
		}
	}
	
	ll ret=0;
	FOR(x1,W) FOR(x2,W) ret+=dp[(H+W-2)/2%2][x1][x2];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}