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

int H,W,K;
string S[1010];

int num[1010][1010];
int base[1010][1010];

void dfs(int cy,int cx,int by,int bx) {
	base[cy][cx]=by*10000+bx;
	int i;
	FOR(i,4) {
		int dd[4]={1,0,-1,0};
		int ty=cy+dd[i];
		int tx=cx+dd[i^1];
		if(S[ty][tx]=='.') {
			if(base[ty][tx]==-1) dfs(ty,tx,by,bx);
		}
		else num[by][bx]++;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	MINUS(base);
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.' && base[y][x]==-1) dfs(y,x,y,x);
	
	FOR(i,K) {
		cin>>j>>k;
		
		y = base[j-1][k-1]/10000;
		x = base[j-1][k-1]%10000;
		cout<<num[y][x]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}