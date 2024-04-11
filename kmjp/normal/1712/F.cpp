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
int P[1010101],D[1010101];
vector<int> E[1010101];
int F[1010101];
int T,X;
int ret;
vector<int> val[2020202];

void dfs(int cur,int pre) {
	val[cur].clear();
	if(cur!=pre) D[cur]=D[pre]+1;
	int i,j;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		if(val[e].size()>val[cur].size()) swap(val[cur],val[e]);
		
		FOR(i,val[e].size()) {
			while(1) {
				int j=max(0,ret-i-X);
				if(j>=val[cur].size()) break;
				if(val[e][i]+val[cur][j]-2*D[cur]<ret) break;
				ret++;
			}
		}
		FOR(i,val[e].size()) val[cur][i]=max(val[cur][i],val[e][i]);
	}
	while(1) {
		int j=max(0,ret-F[cur]-X);
		if(j>=val[cur].size()) break;
		if(D[cur]+val[cur][j]-2*D[cur]<ret) break;
		ret++;
	}
	if(F[cur]>=val[cur].size()) val[cur].push_back(D[cur]);
	else val[cur][F[cur]]=max(val[cur][F[cur]],D[cur]);
	/*
	cout<<cur<<" ";
	FORR(v,val[cur]) cout<<v<<",";
	cout<<endl;
	*/
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		E[x-1].push_back(i+1);
		E[i+1].push_back(x-1);
	}
	queue<int> Q;
	FOR(i,N) {
		if(E[i].size()==1) Q.push(i);
		else F[i]=1<<30;
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,E[cur]) if(F[e]==1<<30) {
			F[e]=F[cur]+1;
			Q.push(e);
		}
	}
	int root;
	FOR(i,N) if(E[i].size()>=2) root=i;
	
	cin>>T;
	while(T--) {
		cin>>X;
		ret=0;
		dfs(root,root);
		cout<<ret-1<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}