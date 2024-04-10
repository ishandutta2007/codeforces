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

pair<int,int> P[5050];
ll T[5050];
ll X[5050];

ll mt[5050];
int dp[5050][5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i+1].first>>P[i+1].second;
	}
	N++;
	sort(P,P+N);
	FOR(i,N) {
		T[i]=P[i].first;
		X[i]=P[i].second;
	}
	
	FOR(i,N) mt[i]=1LL<<60;
	mt[0]=0;
	FOR(i,N-1) {
		if(mt[i]<=T[i]) {
			mt[i+1]=min(mt[i+1],max(T[i],mt[i]+abs(X[i+1]-X[i])));
			for(j=i+2;j<N;j++) {
				ll arrive=max(T[i],mt[i]+abs(X[j]-X[i]));
				ll deadline=T[i+1]-abs(X[j]-X[i+1]);
				if(arrive<=deadline) dp[i+1][j]=1;
			}
		}
		if(dp[i][i+1]&&i+2<N) {
			mt[i+2]=min(mt[i+2],max(T[i+1],T[i]+abs(X[i+2]-X[i])));
			for(j=i+3;j<N;j++) {
				ll arrive=max(T[i+1],T[i]+abs(X[j]-X[i]));
				ll deadline=T[i+2]-abs(X[j]-X[i+2]);
				if(arrive<=deadline) dp[i+2][j]=1;
			}
		}
		for(j=i+2;j<N;j++) if(dp[i][j]) {
			if(T[i+1]-T[i]>=abs(X[i+1]-X[i])) dp[i+1][j]=1;
		}
	}
	
	if(mt[N-1]<=T[N-1]||dp[N-2][N-1]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}