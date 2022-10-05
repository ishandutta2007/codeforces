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
int A[303030],B[303030];

vector<pair<int,int>> E[606060];
int D[606060];
int from[606060];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) cin>>B[i+1];
	
	FOR(i,N) {
	}
	for(i=1;i<=N;i++) {
		E[i-1].push_back({i,0});
		E[i].push_back({i+(N+1)+B[i],0});
		E[i+(N+1)].push_back({i-A[i],1});
	}
	FOR(i,2*N+2) D[i]=1<<20;
	deque<int> Q;
	D[(N+1)+N]=0;
	Q.push_back(2*N+1);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop_front();
		FORR2(e,c,E[cur]) {
			if(D[e]>D[cur]+c) {
				D[e]=D[cur]+c;
				if(c==0) {
					Q.push_front(e);
				}
				else {
					Q.push_back(e);
				}
				from[e]=cur;
			}
		}
	}
	
	if(D[0]==1<<20) cout<<-1<<endl;
	else {
		vector<int> cur={0},ret={0};
		while(cur.back()!=N*2+1) {
			cur.push_back(from[cur.back()]);
			if(cur.size()>=2&&cur.back()<=N&&cur[cur.size()-2]>N) ret.push_back(cur.back());
		}
		reverse(ALL(ret));
		cout<<ret.size()<<endl;
		FORR(e,ret) cout<<e<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}