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

int N,T;
set<pair<int,int>> S;

int ask(int N) {
	int r;
	cout<<"? 1 "<<N<<endl;
	cin>>r;
	r=N-r;
	S.insert({r,N});
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	int first=1;
	while(T--) {
		cin>>x;
		if(first) {
			S.insert({0,0});
			ask(N);
			first=0;
		}
		
		auto it=S.lower_bound({x,0});
		int R=it->second;
		int L=prev(it)->second;
		while(L+1<R) {
			int M=(L+R)/2;
			if(ask(M)>=x) R=M;
			else L=M;
		}
		cout<<"! "<<R<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}