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
int N,Q;
ll S[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(S);
		cin>>N>>Q;
		FOR(i,N) {
			cin>>x>>y;
			S[x][y]+=x*y;
		}
		FOR(x,1005) FOR(y,1005) {
			if(x) S[x][y]+=S[x-1][y];
			if(y) S[x][y]+=S[x][y-1];
			if(x&&y) S[x][y]-=S[x-1][y-1];
		}
		FOR(i,Q) {
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<S[x2-1][y2-1]-S[x1][y2-1]-S[x2-1][y1]+S[x1][y1]<<endl;
		}
	}
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}