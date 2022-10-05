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
ll N,M,K;
set<int> V[102][102];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V[1][1].insert(0);
	for(i=1;i<=100;i++) {
		for(j=1;j<=100;j++) {
			FORR(v,V[i][j]) {
				V[i+1][j].insert(v+j);
				V[i][j+1].insert(v+i);
			}
		}
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		if(V[N][M].count(K)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}