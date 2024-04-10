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

vector<pair<char,int> > RLE(string S) {
	vector<pair<char,int> > V;
	FORR(r,S) {
		if(V.size() && V.back().first==r) V.back().second++;
		else V.push_back({r,1});
	}
	return V;
}

int N;
string S,T;

int check(vector<pair<char,int>> a,vector<pair<char,int>> b) {
	if(a.size()!=b.size()) return 0;
	int i;
	FOR(i,a.size()) {
		if(a[i].first!=b[i].first) return 0;
		if(a[i].second>b[i].second) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>S>>T;
		if(check(RLE(S),RLE(T))) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}