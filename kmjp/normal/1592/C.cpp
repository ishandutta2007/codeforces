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


int T,K,N;
int A[101010];
vector<int> E[101010];
int sum=0;
int cnt;

int dfs(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) A[cur]^=dfs(e,cur);
	
	if(cur&&A[cur]==sum) {
		cnt++;
		A[cur]=0;
	}
	return A[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&K);
		sum=0;
		FOR(i,N) {
			scanf("%d",&A[i]);
			sum^=A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			scanf("%d%d",&x,&y);
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		cnt=0;
		dfs(0,0);
		
		if(sum==0) {
			cout<<"YES"<<endl;
		}
		else {
			if(K>=3&&cnt>=2) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}