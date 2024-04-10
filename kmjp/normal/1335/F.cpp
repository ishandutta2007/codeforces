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

int T;
int H,W;
string S[1010101];
string C[1010101];


int num[1010101][2];
int nex[1010101][30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) cin>>C[y];
		FOR(y,H) cin>>S[y];
		FOR(i,H*W) num[i][0]=num[i][1]=0;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='L') nex[y*W+x][0]=y*W+x-1;
			if(S[y][x]=='R') nex[y*W+x][0]=y*W+x+1;
			if(S[y][x]=='U') nex[y*W+x][0]=(y-1)*W+x;
			if(S[y][x]=='D') nex[y*W+x][0]=(y+1)*W+x;
		}
		FOR(i,29) {
			FOR(j,H*W) nex[j][i+1]=nex[nex[j][i]][i];
		}
		FOR(i,H*W) num[nex[i][29]][C[i/W][i%W]-'0']++;
		int cnt[2]={};
		FOR(i,H*W) {
			cnt[0]+=min(1,num[i][0]+num[i][1]);
			cnt[1]+=min(1,num[i][0]);
		}
		cout<<cnt[0]<<" "<<cnt[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}