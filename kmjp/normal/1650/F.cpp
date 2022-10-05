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

int t,N,M;
vector<int> cand[101010];
int E[101010],T[101010],P[101010];
int A[101010];

pair<int,int> from[101010][101];
ll dp[101010][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>t;
	while(t--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			cand[i].clear();
		}
		FOR(i,M) {
			cin>>E[i]>>T[i]>>P[i];
			cand[E[i]-1].push_back(i);
		}
		
		vector<int> ret;
		int cur=0;
		FOR(i,N) {
			FOR(k,cand[i].size()+1) FOR(j,101) dp[k][j]=1LL<<60;
			dp[0][0]=0;
			FOR(k,cand[i].size()) {
				int p=P[cand[i][k]],t=T[cand[i][k]];
				FOR(j,101) {
					if(dp[k+1][j]>dp[k][j]) {
						dp[k+1][j]=dp[k][j];
						from[k+1][j]={j,-1};
					}
					if(dp[k+1][min(j+p,100)]>dp[k][j]+t) {
						dp[k+1][min(j+p,100)]=dp[k][j]+t;
						from[k+1][min(j+p,100)]={j,cand[i][k]};
					}
				}
				
			}
			if(cur+dp[cand[i].size()][100]>A[i]) break;
			cur+=dp[cand[i].size()][100];
			
			int p=100;
			k=cand[i].size();
			while(k) {
				if(from[k][p].second!=-1) {
					ret.push_back(from[k][p].second);
					p=from[k][p].first;
				}
				k--;
			}
		}
		if(i<N) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret.size()<<endl;
			FORR(r,ret) cout<<r+1<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}