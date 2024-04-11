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

int H,W,K;
int A[101][101];
int B[202];
int M[202];
int D[202];

pair<int,int> hoge() {
	int ma=0,del=0;
	int i,j;
	FOR(i,H) if(B[i]) {
		int d=0,m=0;
		FOR(j,i) d+=B[j];
		for(j=i;j<i+K;j++) m+=B[j];
		if(m>ma) ma=m,del=d;
	}
	
	return {ma,del};
	
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	int cnt=0,del=0;
	FOR(x,W) {
		FOR(y,H) B[y]=A[y][x];
		auto ret=hoge();
		cnt+=ret.first;
		del+=ret.second;
	}
	cout<<cnt<<" "<<del<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}