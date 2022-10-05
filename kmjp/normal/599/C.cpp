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


int N;
int H[101010];
int R[101010];
map<int,vector<int> > M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>H[i];
		M[H[i]].push_back(i);
	}
	
	int right=-1;
	FORR(r,M) {
		int nr=-1;
		FORR(r2,r.second) nr = max(nr,r2), R[r2]=right;
		right = max(nr,right);
	}
	
	x=0,r=-1;
	FOR(i,N) {
		if(r<i) x++;
		r=max(r,R[i]);
	}
	cout<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}