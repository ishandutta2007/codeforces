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

int T,H,W;
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int pApB=-10000000;
		int pAmB=-10000000;
		int mApB=-10000000;
		int mAmB=-10000000;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) if(S[y][x]=='B') {
				pApB=max(pApB,y+x);
				pAmB=max(pAmB,y-x);
				mApB=max(mApB,-y+x);
				mAmB=max(mAmB,-y-x);
			}
		}
		int ty=0,tx=0,pat=1000000;
		FOR(y,H) FOR(x,W) {
			int ma=-10000000;
			ma=max(ma,pApB-y-x);
			ma=max(ma,pAmB-y+x);
			ma=max(ma,mApB+y-x);
			ma=max(ma,mAmB+y+x);
			if(ma<pat) {
				pat=ma;
				ty=y+1;
				tx=x+1;
			}
		}
		cout<<ty<<" "<<tx<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}