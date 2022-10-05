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

int memo[101][101][2];

int win(int C0,int C1,int goal) {
	
	if(C0==0&&C1==0) return goal==0;
	
	if(memo[C0][C1][goal]>=0) return memo[C0][C1][goal];
	int ret=0;
	if(C0&&win(C0-1,C1,goal^(C1&1)^1)==0) ret=1;
	if(C1&&win(C0,C1-1,goal^(C1&1)^1)==0) ret=1;
	
	return memo[C0][C1][goal]=ret;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>T;
	while(T--) {
		cin>>N;
		int C[2]={};
		FOR(i,N) {
			cin>>x;
			C[abs(x)&1]++;
		}
		
		if(win(C[0],C[1],0)) {
			cout<<"Alice"<<endl;
		}
		else {
			cout<<"Bob"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}