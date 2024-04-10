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

int N,M;
vector<pair<int,int>> E[101010];
ll D[101010][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	FOR(i,N) FOR(j,51) D[i][j]=1LL<<60;
	D[0][0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second/100;
		int d=Q.top().second%100;
		
		Q.pop();
		if(D[cur][d]!=co) continue;
		if(d==0) {
			FORR2(e,c,E[cur]) if(D[e][c]>co) {
				D[e][c]=co;
				Q.push({-co,e*100+c});
			}
		}
		else {
			FORR2(e,c,E[cur]) if(D[e][0]>co+(d+c)*(d+c)) {
				D[e][0]=co+(d+c)*(d+c);
				Q.push({-D[e][0],e*100});
			}
		}
	}
	FOR(i,N) {
		if(D[i][0]==1LL<<60) cout<<-1<<" ";
		else cout<<D[i][0]<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}