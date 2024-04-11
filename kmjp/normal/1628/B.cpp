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
string S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>S[i];
		
		set<string> V[4];
		
		FOR(i,N) {
			if(S[i][0]==S[i].back()) break;
			string T=S[i];
			reverse(ALL(T));
			if(S[i].size()==2) {
				if(V[2].count(T)) break;
				if(V[1].count(T)) break;
				V[2].insert(S[i]);
			}
			if(S[i].size()==3) {
				if(V[2].count(T.substr(0,2))) break;
				if(V[3].count(T)) break;
				V[3].insert(S[i]);
				V[1].insert(S[i].substr(0,2));
			}
		}
		if(i!=N) {
			cout<<"YES"<<endl;
			continue;
		}
		else {
			cout<<"NO"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}