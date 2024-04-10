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
ll K;
string S;

int nex[102][26];
ll num[101];
ll dp[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	dp[0][0]=1;
	num[0]=1;
	FOR(x,N) {
		FOR(i,26) {
			for(y=x;y<N;y++) if(S[y]=='a'+i) {
				FOR(j,100) {
					dp[y+1][j+1]+=dp[x][j];
					num[j+1]+=dp[x][j];
					dp[y+1][j+1]=min(dp[y+1][j+1],1LL<<40);
					num[j+1]=min(num[j+1],1LL<<40);
				}
				break;
			}
		}
	}
	
	ll ret=0;
	for(i=100;i>=0;i--) {
		ll v=min(K,num[i]);
		ret+=v*(N-i);
		K-=v;
	}
	if(K) cout<<-1<<endl;
	else cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}