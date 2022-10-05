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

int N;
map<pair<int,int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		x=y=0;
		FORR(c,s) {
			if(c=='(') x++;
			else x--;
			y=min(y,x);
		}
		M[{x,y}]++;
	}
	vector<vector<ll>> V;
	FORR(m,M) V.push_back({m.first.first,m.first.second,m.second});
	
	ll ret=0;
	FORR(v,V) FORR(v2,V) {
		if(v[1]>=0 && v[0]+v2[0]==0 && v[0]+v2[1]>=0) ret+=v[2]*v2[2];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}