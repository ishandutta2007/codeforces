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

int N,M;
vector<int> X;
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		X.push_back(x);
	}
	sort(ALL(X));
	int ret=0;
	FOR(i,M) {
		cin>>j>>x>>y;
		if(j>1) continue;
		R.push_back(x);
	}
	sort(ALL(R));
	reverse(ALL(R));
	int mi=1<<30;
	FORR(x,X) {
		while(R.size()&&R.back()<x) R.pop_back();
		mi=min(mi,ret+(int)R.size());
		ret++;
	}
	while(R.size()&&R.back()<1000000000) R.pop_back();
	mi=min(mi,ret+(int)R.size());
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}