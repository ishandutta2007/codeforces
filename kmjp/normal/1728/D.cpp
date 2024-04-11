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
string S;

int memo[2222][2222];
int comp(int pre,char a,char b) {
	if(pre) return pre;
	if(a<b) return 1;
	if(a==b) return 0;
	return -1;
}

int win(int L,int R) {
	if(L==R) return 0;
	if(memo[L][R]!=-2) return memo[L][R];
	int ret=-1;
	
	int pat[4]={};
	pat[0]=comp(win(L+2,R),S[L],S[L+1]);
	pat[1]=comp(win(L+1,R-1),S[L],S[R-1]);
	pat[2]=comp(win(L+1,R-1),S[R-1],S[L]);
	pat[3]=comp(win(L,R-2),S[R-1],S[R-2]);
	
	
	
	return memo[L][R]=max(min(pat[0],pat[1]),min(pat[2],pat[3]));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(x,N+2) FOR(y,N+2) memo[x][y]=-2;
		x=win(0,N);
		if(x==1) cout<<"Alice"<<endl;
		else if(x==0) cout<<"Draw"<<endl;
		else cout<<"Bob"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}