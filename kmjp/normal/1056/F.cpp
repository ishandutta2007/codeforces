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

int TC;
int N;
double T,C;
pair<int,int> P[101];

double dp[101][1001];
double po[102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,102) po[i]=pow(1.0/0.9,i);
	
	
	cin>>TC;
	while(TC--) {
		cin>>N;
		cin>>C>>T;
		FOR(i,N) cin>>P[i].first>>P[i].second;
		sort(P,P+N);
		reverse(P,P+N);
		
		FOR(i,101) FOR(j,1001) dp[i][j]=1e12;
		dp[0][0]=0;
		
		FOR(i,N) {
			for(x=i;x>=0;x--) {
				for(y=10*x;y>=0;y--) if(dp[x][y]<1e12) {
					dp[x+1][y+P[i].second]=min(dp[x+1][y+P[i].second], dp[x][y]+P[i].first*po[x+1]);
				}
			}
		}
		
		int ma=0;
		FOR(x,N+1) FOR(y,x*10+1) if(y>ma) {
			double D=dp[x][y];
			
			
			double train=0;
			if(D*C>1) {
				train=(sqrt(D*C)-1)/C;
			}
			double S=1+train*C;
			if(D/S+train+10*x<=T) ma=y;
			
			
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}