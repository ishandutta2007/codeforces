#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N;
string S[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(y,N) cin>>S[y];
		
		vector<pair<int,int>> R;
		if(S[1][0]==S[0][1]) {
			if(S[N-2][N-1]==S[1][0]) R.push_back({N-2,N-1});
			if(S[N-1][N-2]==S[1][0]) R.push_back({N-1,N-2});
		}
		else if(S[N-1][N-2]==S[N-2][N-1]) {
			if(S[N-2][N-1]==S[1][0]) R.push_back({1,0});
			if(S[N-2][N-1]==S[0][1]) R.push_back({0,1});
		}
		else {
			R.push_back({0,1});
			if(S[N-2][N-1]==S[1][0]) R.push_back({N-2,N-1});
			if(S[N-1][N-2]==S[1][0]) R.push_back({N-1,N-2});
		}
		
		cout<<R.size()<<endl;
		FORR(r,R) cout<<r.first+1<<" "<<r.second+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}