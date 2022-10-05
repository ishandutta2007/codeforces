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

int gr[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	for(i=1;i<=1000;i++) {
		set<int> S;
		for(x=2;x<i;x++) if(i%x==0) S.insert(gr[i-x]);
		while(S.count(gr[i])) gr[i]++;
		if(i>=4) {
			if(i%2==0&&gr[i]==0) cout<<i<<" "<<gr[i]<<endl;
			if(i%2==1&&gr[i]) cout<<i<<" "<<gr[i]<<endl;
		}
		
	}
	*/
	
	cin>>T;
	while(T--) {
		cin>>N;
		x=N;
		while(x%4==0) x/=4;
		if(x==2) {
			cout<<"Bob"<<endl;
		}
		else if(N%2==0) {
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