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

int T;
int N;
vector<int> E[202020];
vector<int> C[2];
vector<int> cand[20];
int P[202020];

void dfs(int cur,int pre,int c) {
	C[c].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,c^1);
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
		C[0].clear();
		C[1].clear();
		dfs(0,0,0);
		FOR(i,20) cand[i].clear();
		int la;
		for(i=1;i<=N;i++) {
			x=0;
			while(1<<(x+1)<=i) x++;
			cand[x].push_back(i);
			la=x;
		}
		if(C[0].size()<cand[la].size()) swap(C[0],C[1]);
		for(i=la;i>=0;i--) if(C[0].size()>=cand[i].size()) {
			while(cand[i].size()) {
				P[C[0].back()]=cand[i].back();
				C[0].pop_back();
				cand[i].pop_back();
			}
		}
		FOR(i,19) {
			FORR(a,cand[i]) {
				P[C[1].back()]=a;
				C[1].pop_back();
			}
		}
		FOR(i,N) cout<<P[i]<<" ";
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}