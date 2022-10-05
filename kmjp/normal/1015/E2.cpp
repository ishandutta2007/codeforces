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
string S[1010];
string T[1010];

int U[1010][1010],D[1010][1010],L[1010][1010],R[1010][1010];
int B[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		T[y]=S[y];
		FORR(c,T[y]) c='.';
	}
	
	FOR(y,H) {
		FOR(x,W) if(S[y][x]=='*') L[y][x]=1+(x?L[y][x-1]:0);
		for(x=W-1;x>=0;x--) if(S[y][x]=='*') R[y][x]=1+R[y][x+1];
	}
	FOR(x,W) {
		FOR(y,H) if(S[y][x]=='*') U[y][x]=1+(y?U[y-1][x]:0);
		for(y=H-1;y>=0;y--) if(S[y][x]=='*') D[y][x]=1+D[y+1][x];
	}
	
	vector<vector<int>> V;
	FOR(y,H) FOR(x,W) {
		B[y][x]=min({L[y][x],R[y][x],U[y][x],D[y][x]});
		if(B[y][x]>=2) V.push_back({y+1,x+1,B[y][x]-1});
	}
	
	FOR(y,H) {
		int left=0;
		FOR(x,W) {
			left--;
			if(B[y][x]>=2) left=max(left,B[y][x]);
			if(left>0) T[y][x]='*';
		}
		left=0;
		for(x=W-1;x>=0;x--) {
			left--;
			if(B[y][x]>=2) left=max(left,B[y][x]);
			if(left>0) T[y][x]='*';
		}
	}
	FOR(x,W) {
		int left=0;
		FOR(y,H) {
			left--;
			if(B[y][x]>=2) left=max(left,B[y][x]);
			if(left>0) T[y][x]='*';
		}
		left=0;
		for(y=H-1;y>=0;y--) {
			left--;
			if(B[y][x]>=2) left=max(left,B[y][x]);
			if(left>0) T[y][x]='*';
		}
	}
	
	
	FOR(y,H) if(S[y]!=T[y]) return _P("-1\n");
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}