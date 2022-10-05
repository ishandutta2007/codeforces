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

ll X,Y;
string A,B,C,D;

set<string> memo;

int inc(string s,string t) {
	int i;
	while(s.back()=='0') s.pop_back();
	for(i=0;i+s.size()<=t.size();i++) {
		if(t.substr(i,s.size())==s) return 1;
	}
	return 0;
}

void dfs(string s) {
	if(s==B) {
		cout<<"YES"<<endl;
		exit(0);
	}
	
	if(memo.count(s)) return;
	memo.insert(s);
	string a0=s+"0";
	string a1=s+"1";
	reverse(ALL(a0));
	reverse(ALL(a1));
	while(a0[0]=='0') a0=a0.substr(1);
	while(a1[0]=='0') a1=a1.substr(1);
	if(inc(a0,C)||inc(a0,D)) dfs(a0);
	if(inc(a1,C)||inc(a1,D)) dfs(a1);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	while(X) {
		A+='0'+(X%2);
		X/=2;
	}
	while(Y) {
		B+='0'+(Y%2);
		Y/=2;
	}
	
	reverse(ALL(A));
	D=B;
	reverse(ALL(B));
	C=B;
	while(C.back()=='0') C.pop_back();
	while(D.back()=='0') D.pop_back();
	
	dfs(A);
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}