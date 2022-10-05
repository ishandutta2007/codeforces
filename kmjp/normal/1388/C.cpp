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


int T;
int N;
ll M;
ll P[101010];
ll H[101010];
int ok;
vector<int> E[101010];


void dfs(int cur,int pre) {
	ll TH=0,TP=0;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		TH+=H[e];
		TP+=P[e];
	}
	
	if(abs(H[cur]%2)!=(P[cur]+TP)%2) ok=0;
	ll lo=TH-P[cur];
	ll hi=TP+P[cur];
	if(H[cur]<lo || hi<H[cur]) ok=0;
	
	
	P[cur]+=TP;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			cin>>P[i];
		}
		FOR(i,N) cin>>H[i];
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		ok=1;
		dfs(0,0);
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}