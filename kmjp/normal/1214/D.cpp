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
string S[1010101];
int num[2020202];
vector<int> A[1010101],B[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		A[y].resize(W);
		B[y].resize(W);
	}
	A[0][0]=1;
	B[H-1][W-1]=1;
	
	
	for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
		if(y==H-1&&x==W-1) continue;
		if(y==0&&x==0) continue;
		if(S[y][x]=='#') continue;
		if(y+1<H&&B[y+1][x]==1) B[y][x]=1;
		if(x+1<W&&B[y][x+1]==1) B[y][x]=1;
	}
	FOR(y,H) FOR(x,W) {
		if(y==H-1&&x==W-1) continue;
		if(y==0&&x==0) continue;
		if(S[y][x]=='#') continue;
		if(y&&A[y-1][x]==1) A[y][x]=1;
		if(x&&A[y][x-1]==1) A[y][x]=1;
		if(B[y][x]&&A[y][x]) num[y+x]++;
	}
	
	int mi=2020202;
	for(i=1;i<H+W-2;i++) mi=min(mi,num[i]);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}