#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,S;
int sel[101010],buy[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		cin>>s>>x>>y;
		if(s=="B") buy[x]+=y;
		if(s=="S") sel[x]+=y;
	}
	
	int ma=100000;
	vector<int> R;
	FOR(i,101010) if(sel[i]) R.push_back(i);
	for(i=min(S-1,(int)R.size()-1);i>=0;i--) _P("S %d %d\n",R[i],sel[R[i]]);
	x=S;
	for(i=100000;i>=0 && x;i--) if(buy[i]) x--, _P("B %d %d\n",i,buy[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}