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

int T,N;
vector<int> E[303030];
int save[303030];
int C[303030];

void dfs(int cur,int pre) {
	int i;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) {
		swap(E[cur][i],E[cur].back());
		E[cur].pop_back();
		break;
	}
	
	if(E[cur].empty()) {
		save[cur]=0;
		C[cur]=1;
	}
	else if(E[cur].size()==1) {
		dfs(E[cur][0],cur);
		save[cur]=C[E[cur][0]]-1;
		C[cur]=1+C[E[cur][0]];
	}
	else if(E[cur].size()==2) {
		int a=E[cur][0];
		int b=E[cur][1];
		dfs(a,cur);
		dfs(b,cur);
		save[cur]=max(C[a]-1+save[b],C[b]-1+save[a]);
		C[cur]=1+C[a]+C[b];
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0);
		cout<<save[0]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}