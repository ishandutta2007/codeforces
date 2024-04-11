#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<pair<int,int>> P;
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int X=0,Y=0;
	
	P.push_back({0,0});
	FORR(c,S) {
		if(c=='U') Y++;
		if(c=='D') Y--;
		if(c=='R') X++;
		if(c=='L') X--;
		P.push_back({X,Y});
	}
	int ret=0;
	for(i=1;i<P.size()-1;i++) {
		if(P[i].first==0 && P[i].second==0) continue;
		if(P[i].first!=P[i].second) continue;
		if(P[i-1].first-P[i-1].second != P[i+1].first-P[i+1].second) ret++;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}