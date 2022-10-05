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

int N,K;
int P[5050],R[5050],inv[5050];
int dp[5050][1<<8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>P[i];
		R[P[i]]=i;
	}
	for(x=1;x<=N;x++) for(y=x+1;y<=N;y++) if(R[y]<R[x]) inv[x]++;
	
	
	FOR(i,5010) FOR(j,256) dp[i][j]=1<<30;
	for(i=1;i<=K+1;i++) {
		int mask=0;
		FOR(j,K) if(i-(j+1)<=0) mask|=1<<j;
		dp[i][mask]=inv[i];
	}
	
	int mask;
	for(i=1;i<=N;i++) for(mask=0;mask<1<<K;mask++) if(dp[i][mask]<1<<30) {
		//cout<<"$"<<i<<" "<<mask<<" "<<dp[i][mask]<<endl;
		// add mi;
		FOR(j,K) if((mask&(1<<j))==0) {
			x=i-(j+1);
			
			int cost=inv[x];
			FOR(k,j) {
				y=i-(k+1);
				if(mask&(1<<k)) {
					if(R[y]<R[x]) cost--;
					if(R[y]>R[x]) cost++;
				}
			}
			if(R[i]<R[x]) cost--;
			if(R[i]>R[x]) cost++;
			//cout<<"#"<<x<<" "<<cost<<endl;
			dp[i][mask|(1<<j)]=min(dp[i][mask|(1<<j)],dp[i][mask]+cost);
		}
		for(j=i+1;j<=min(N,i+K+1);j++) {
			FOR(x,K) if((mask&(1<<x))==0) {
				y=i-(x+1);
				if(y<j-K) break;
			}
			if(x!=K) continue;
			int nm=((mask<<(j-i))|(1<<(j-i-1)))&((1<<K)-1);
			//cout<<i<<":"<<mask<<" "<<j<<":"<<nm<<" "<<dp[i][mask]<<"+"<<inv[j]<<endl;
			dp[j][nm]=min(dp[j][nm],dp[i][mask]+inv[j]);
			
		}
	}
	cout<<dp[N][(1<<K)-1]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}