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

vector<int> V;
vector<int> W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(j,2) {
		FOR(i,400) {
			int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			if(i%4==0 && (i==0 || i%100!=0)) M[1]++;
			FOR(x,12) V.push_back(M[x]);
		}
	}
	
	cin>>x;
	FOR(i,x) {
		cin>>y;
		W.push_back(y);
	}
	
	FOR(i,V.size()-W.size()+1) {
		int ok=1;
		FOR(j,W.size()) if(V[i+j]!=W[j]) ok=0;
		if(ok==1) return _P("Yes\n");
	}
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}