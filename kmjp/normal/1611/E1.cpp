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
int N,K;
int D[202020][2];
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			D[i][0]=D[i][1]=1<<30;
			E[i].clear();
		}
		queue<int> Q;
		FOR(i,K) {
			cin>>x;
			x--;
			D[x][1]=0;
			Q.push(N+x);
		}
		D[0][0]=0;
		Q.push(0);
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		while(Q.size()) {
			int cur=Q.front()%N;
			int id=Q.front()/N;
			Q.pop();
			FORR(e,E[cur]) if(D[e][id]>D[cur][id]+1) {
				D[e][id]=D[cur][id]+1;
				Q.push(id*N+e);
			}
		}
		int ok=0;
		FOR(i,N) if(i&&E[i].size()==1&&D[i][0]<D[i][1]) ok=1;
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