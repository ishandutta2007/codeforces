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

vector<int> A[1010101];
vector<int> B[1010101];
vector<int> C[1010101];


int filled(int y,int x,int r) {
	if(y-r<0) return 0;
	if(y+r>=H) return 0;
	if(x-r<0) return 0;
	if(x+r>=W) return 0;
	ll num=A[y+1+r][x+1+r]-A[y-r][x+1+r]-A[y+1+r][x-r]+A[y-r][x-r];
	
	return num==1LL*(2*r+1)*(2*r+1);
	
}

int ok(int r) {
	int y,x;
	FOR(y,H+1) {
		C[y].clear();
		C[y].resize(W+1);
	}
	FOR(y,H) FOR(x,W) if(B[y][x]>=r) {
		C[max(0,y-(r-1))][max(0,x-(r-1))]++;
		C[max(0,y-(r-1))][min(x+(r-1)+1,W)]--;
		C[min(y+(r-1)+1,H)][max(0,x-(r-1))]--;
		C[min(y+(r-1)+1,H)][min(x+(r-1)+1,W)]++;
	}
	
	FOR(y,H) FOR(x,W) {
		if(y) C[y][x]+=C[y-1][x];
		if(x) C[y][x]+=C[y][x-1];
		if(y&&x) C[y][x]-=C[y-1][x-1];
	}
		
	FOR(y,H) FOR(x,W) {
		if(C[y][x]==0 && S[y][x]=='X') return 0;
		if(C[y][x]>0 && S[y][x]=='.') return 0;
	}
	
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&H,&W);
	A[0].resize(W+2);
	FOR(y,H) {
		S[y].resize(W+1);
		scanf("%s",S[y].c_str());
		S[y].resize(W);
		
		A[y+1].resize(W+2);
		FOR(x,W+2) {
			A[y+1][x]=A[y][x];
			if(x) {
				A[y+1][x]+=A[y+1][x-1];
				A[y+1][x]-=A[y][x-1];
			}
			if(x>=1&&x<=W) A[y+1][x]+=S[y][x-1]=='X';
		}
		B[y].resize(W);
	}
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='X') {
		r=0;
		for(i=20;i>=0;i--) if(filled(y,x,r+(1<<i))) r+=1<<i;
		B[y][x]=r+1;
	}
	
	int ret=1;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	
	_P("%d\n",ret-1);
	ok(ret);
	FOR(y,H) {
		FOR(x,W) {
			if(B[y][x]>=ret) _P("X");
			else _P(".");
		}
		_P("\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}