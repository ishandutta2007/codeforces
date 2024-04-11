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

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> V;
	cin>>S;
	FORR(c,S) {
		if(V.empty() || V.back().first!=c) V.push_back({c,0});
		V.back().second++;
	}
	
	int ret=0;
	while(V.size()>=2) {
		ret++;
		vector<pair<int,int>> V2;
		FOR(i,V.size()) {
			if(i) V[i].second--;
			if(i<V.size()-1) V[i].second--;
			if(V[i].second>=1) {
				if(V2.size() && V2.back().first==V[i].first) V2.back().second+=V[i].second;
				else V2.push_back(V[i]);
			}
		}
		swap(V,V2);
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}