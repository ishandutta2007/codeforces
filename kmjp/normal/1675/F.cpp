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

int T,N,K;
int X,Y;
int A[202020];
vector<int> E[202020];

int D[2][202020];
int ret;

int dfs(int cur,int pre) {
	int ok=A[cur];
	FORR(e,E[cur]) {
		if(e==pre) continue;
		if(D[0][e]+D[1][e]==D[0][Y]) continue;
		int r=dfs(e,cur);
		if(r) {
			ret+=2;
			ok=1;
		}
	}
	return ok;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>X>>Y;
		X--,Y--;
		FOR(i,N) {
			A[i]=0;
			E[i].clear();
			D[0][i]=D[1][i]=1<<20;
		}
		FOR(i,K) {
			cin>>x;
			A[x-1]=1;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		queue<int> Q;
		D[0][X]=D[1][Y]=0;
		Q.push(X);
		Q.push(N+Y);
		while(Q.size()) {
			int cur=Q.front()%N;
			int id=Q.front()/N;
			Q.pop();
			FORR(e,E[cur]) if(D[id][e]==1<<20) {
				D[id][e]=D[id][cur]+1;
				Q.push(id*N+e);
			}
		}
		ret=D[0][Y];
		FOR(i,N) if(D[0][i]+D[1][i]==D[0][Y]) dfs(i,i);
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}