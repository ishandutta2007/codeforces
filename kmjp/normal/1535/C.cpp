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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		set<int> T[2];
		FOR(i,S.size()) {
			if(i%2==1) {
				if(S[i]=='0') S[i]='1';
				else if(S[i]=='1') S[i]='0';
			}
			if(S[i]=='0') T[0].insert(i);
			if(S[i]=='1') T[1].insert(i);
		}
		T[0].insert(N);
		T[1].insert(N);
		ll ret=0;
		FOR(i,S.size()) {
			T[0].erase(i);
			T[1].erase(i);
			if(S[i]=='0') ret+=*T[1].begin()-i;
			if(S[i]=='1') ret+=*T[0].begin()-i;
			if(S[i]=='?') ret+=max(*T[0].begin(),*T[1].begin())-i;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}