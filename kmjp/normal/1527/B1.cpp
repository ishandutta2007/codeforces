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
string S;

int memo[2010][2010][2][2];

int win(int a01,int b00,int c0,int p) {
	int& ret=memo[a01][b00][c0][p];
	if(ret<=100000) return ret;
	ret=1<<20;
	
	if(a01==0&&b00==0&&c0==0) return ret=0;
	if(a01&&p==0) ret=min(ret,-win(a01,b00,c0,1));
	if(a01) ret=min(ret,1-win(a01-1,b00,c0,0));
	if(b00) ret=min(ret,1-win(a01+1,b00-1,c0,0));
	if(c0) ret=min(ret,1-win(a01,b00,0,0));
	
	return ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	memset(memo,111,sizeof(memo));
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		int a01=0,b00=0,c0=0;
		if(N%2&&S[N/2]=='0') c0++;
		FOR(i,N/2) {
			if(S[i]=='0'&&S[N-1-i]=='0') b00++;
			if(S[i]=='1'&&S[N-1-i]=='0') a01++;
			if(S[i]=='0'&&S[N-1-i]=='1') a01++;
		}
		
		x=win(a01,b00,c0,0);
		if(x>0) cout<<"BOB"<<endl;
		if(x<0) cout<<"ALICE"<<endl;
		if(x==0) cout<<"DRAW"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}