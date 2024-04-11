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

int N,K;
string S;

int vis[5050][5050];
vector<pair<int,int>> nex[26];
void dfs(int cur,int mask) {
	if(vis[cur][mask] || cur+1+mask>N) return;
	vis[cur][mask]=1;
	
	int i;
	nex[S[cur]-'a'].push_back({cur+1,mask});
	FOR(i,K) if(mask&(1<<i)) dfs(cur+(1<<i),mask^(1<<i));
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	while(1<<(K+1)<=N) K++;
	vector<pair<int,int>> now;
	
	now.push_back({0,(1<<K)-1});
	while(now.size()) {
		FOR(i,26) nex[i].clear();
		FORR(n,now) dfs(n.first,n.second);
		char c='z'+1;
		for(i=25;i>=0;i--) if(nex[i].size()) c='a'+i;
		if(c=='z'+1) break;
		cout<<c;
		swap(now,nex[c-'a']);
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}