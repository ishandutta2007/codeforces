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

int mex[5050505];

bool hoge() {
	int i,j,k,l,r,x,y; string s;
	
	if(count(ALL(S),'R')<count(ALL(S),'B')) return 0;
	if(count(ALL(S),'B')<count(ALL(S),'R')) return 1;
	
	int nim=0;
	int num=0;
	int pre=-1;
	FORR(c,S) {
		if(pre==c) {
			nim^=mex[num];
			num=0;
		}
		pre=c;
		num++;
	}
	nim^=mex[num];
	return nim;
}
	

void solve() {
	int i,j;
	
	for(i=1;i<=1000;i++) {
		set<int> S;
		for(j=0;j<=i-2;j++) S.insert(mex[j]^mex[i-2-j]);
		while(S.count(mex[i])) mex[i]++;
	}
	
	for(i=1001;i<=5050101;i++) mex[i]=mex[i-34];
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		if(hoge()) {
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