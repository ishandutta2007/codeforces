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
int A[5050];
int bm[5050][8192];
int can[5050][8192];
vector<int> cand[5050];

void add(int num,int val) {
	can[num][val]=1;
	int i;
	for(i=num+2;i<=5005;i++) {
		if(bm[i][val]) break;
		bm[i][val]=1;
		cand[i].push_back(val);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	add(0,0);
	
	FOR(i,N) {
		cin>>x;
		FORR(c,cand[x+1]) add(x,x^c);
		cand[x+1].clear();
	}
	vector<int> ret;
	FOR(i,8192) if(bm[5003][i]) ret.push_back(i);
	cout<<ret.size()<<endl;
	FORR(c,ret) cout<<c<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}