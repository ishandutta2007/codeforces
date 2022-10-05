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

int H,W,Q;
int A[2049][2049][2];
string S[2048];

ll hoge(ll x,ll y) {
	if(x<=0 || y<=0) return 0;
	ll dx=x/W*W;
	ll dy=y/H*H;
	
	int ind=(__builtin_popcount(x/W)+__builtin_popcount(y/H))%2;
	return x*dy/2+y*dx/2-dx*dy/2+A[y%H][x%W][ind];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) S[y].push_back(S[y][x]^1);
		FOR(x,2*W) S[y+H].push_back(S[y][x]^1);
	}
	H*=2;
	W*=2;
	FOR(y,H) FOR(x,W) FOR(i,2) A[y+1][x+1][i]=A[y][x+1][i]+A[y+1][x][i]-A[y][x][i]+(S[y][x]==('1'^i));
		
	
	while(Q--) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--,y1--;
		
		cout<<hoge(y2,x2)-hoge(y1,x2)-hoge(y2,x1)+hoge(y1,x1)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}