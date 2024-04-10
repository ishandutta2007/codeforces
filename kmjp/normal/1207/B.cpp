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

int H,W;
int A[51][51];
int B[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	vector<pair<int,int>> V;
	FOR(y,H-1) FOR(x,W-1) if(A[y][x] && A[y+1][x] && A[y][x+1] && A[y+1][x+1]) {
		V.push_back({y+1,x+1});
		B[y][x]=B[y+1][x]=B[y][x+1]=B[y+1][x+1]=1;
	}
	
	i=0;
	FOR(y,H) FOR(x,W) i+=A[y][x]!=B[y][x];
	if(i) {
		cout<<-1<<endl;
	}
	else {
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}