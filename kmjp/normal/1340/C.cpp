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
int D[101010];
int G,R;
int dp[10101][1010];
vector<short> ev[12020202];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>D[i];
	sort(D,D+M);
	cin>>G>>R;
	
	FOR(i,M) FOR(x,G+1) dp[i][x]=1<<30;
	dp[0][0]=0;
	priority_queue<pair<int,int>> Q;
	ev[0].push_back(0);
	ll ret=1LL<<30;
	int co;
	FOR(co,12010101) {
		FORR(cur,ev[co]) {
			if(cur>0) {
				ll nex=co+D[cur]-D[cur-1];
				if(co/G==(nex-1)/G) {
					if(dp[cur-1][nex%G]>nex) {
						dp[cur-1][nex%G]=nex;
						ev[nex].push_back(cur-1);
					}
				}
			}
			if(cur<M-1) {
				ll nex=co+D[cur+1]-D[cur];
				if(co/G==(nex-1)/G) {
					if(cur+1==M-1) {
						ret=min(ret,nex);
					}
					else if(dp[cur+1][nex%G]>nex) {
						dp[cur+1][nex%G]=nex;
						ev[nex].push_back(cur+1);
					}
				}
			}
		}
	}
	
	if(ret==1LL<<30) ret=-1;
	else {
		if(ret%G==0) {
			ret=(ret/G-1)*(G+R)+G;
		}
		else {
			ret=ret/G*(G+R)+ret%G;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}