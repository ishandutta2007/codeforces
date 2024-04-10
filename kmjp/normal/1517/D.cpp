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

int H,W,K;
vector<pair<int,int>> E[505*505];
int dp[505*505][11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) {
		FOR(x,W-1) {
			cin>>k;
			E[y*W+x].push_back({y*W+x+1,k});
			E[y*W+x+1].push_back({y*W+x,k});
		}
	}
	FOR(y,H-1) {
		FOR(x,W) {
			cin>>k;
			E[y*W+x].push_back({y*W+x+W,k});
			E[y*W+x+W].push_back({y*W+x,k});
		}
	}
	
	if(K%2==1) {
		FOR(y,H) {
			FOR(x,W) cout<<"-1 ";
			cout<<endl;
		}
		return;
	}
	K/=2;
	FOR(y,H) {
		FOR(x,W) {
			FOR(i,11) dp[y*W+x][i]=1<<30;
		}
	}
	FOR(y,H) {
		FOR(x,W) {
			int y2,x2;
			dp[y*W+x][0]=0;
			int ret=1<<30;
			for(i=0;i<=K;i++) {
				for(y2=max(0,y-i);y2<=min(H-1,y+i);y2++) {
					int lef=i-abs(y2-y);
					for(x2=max(0,x-lef);x2<=min(W-1,x+lef);x2++) {
						//cout<<y<<x<<" "<<y2<<x2<<i<<" "<<dp[y2*W+x2][i]<<endl;
						if(i==K) {
							ret=min(ret,dp[y2*W+x2][K]);
						}
						else {
							FORR2(e,c,E[y2*W+x2]) dp[e][i+1]=min(dp[e][i+1],dp[y2*W+x2][i]+c);
						}
						dp[y2*W+x2][i]=1<<30;
					}
				}
			}
			cout<<ret*2<<" ";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}