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

int N;
int A[101],L[101];
pair<int,int> P[101];

int dp[105][105][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	P[N]={-111111111,0};
	N++;
	sort(P,P+N);
	FOR(i,N) A[i]=P[i].first, L[i]=P[i].second;
	
	FOR(x,N+2) FOR(y,N+2) dp[x][y][0]=dp[x][y][1]=-211111111;
	dp[0][0][0]=dp[0][0][1]=0;
	
	int dir,d2;
	int res=0;
	FOR(x,N) {
		FOR(y,x+1) FOR(dir,2) {
			int R=A[y]+dir*L[y];
			int v=dp[x][y][dir];
			
			int mar=-211111112;
			int bk=-1,bd=-1;
			for(k=x+1;k<N;k++) FOR(d2,2) {
				int R2=A[k]+d2*L[k];
				if(mar<R2) mar=R2,bk=k,bd=d2;
				dp[k][bk][bd]=max(dp[k][bk][bd],v+min(L[k],R2-R) - (R2-mar));
				res=max(dp[k][bk][bd],res);
			}
		}
	}
	
	cout<<res<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}