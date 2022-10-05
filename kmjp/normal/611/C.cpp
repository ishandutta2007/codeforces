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
string S[505];
int ri[505][505];
int down[505][505];
int R[505][505];
int D[505][505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W-1) if(S[y][x]=='.' && S[y][x+1]=='.') ri[y][x]=1;
	FOR(x,W) FOR(y,H-1) if(S[y][x]=='.' && S[y+1][x]=='.') down[y][x]=1;
	for(y=1;y<=502;y++) {
		for(x=1;x<=502;x++) {
			R[y][x] = R[y-1][x]+R[y][x-1]-R[y-1][x-1]+ri[y-1][x-1];
			D[y][x] = D[y-1][x]+D[y][x-1]-D[y-1][x-1]+down[y-1][x-1];
		}
	}
	
	
	cin>>Q;
	while(Q--) {
		int x1,x2,y1,y2;
		cin>>y1>>x1>>y2>>x2;
		
		int sum=0;
		sum += R[y2][x2-1]-R[y1-1][x2-1]-R[y2][x1-1]+R[y1-1][x1-1];
		sum += D[y2-1][x2]-D[y1-1][x2]-D[y2-1][x1-1]+D[y1-1][x1-1];
		cout<<sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}