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

int N;
string S;
int X[10],Y[10];

int valid(int y,int x) {
	if(x<0 || x>=3) return 0;
	if(y<0 || y>=4) return 0;
	if(y==3 && x!=1) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		x=S[i]-'0';
		if(x==0) x=11;
		x--;
		Y[i]=x/3;
		X[i]=x%3;
	}
	
	int pat=0;
	FOR(y,4) FOR(x,3) {
		int ty=y,tx=x;
		int ok=valid(ty,tx);
		FOR(i,N-1) {
			ty+=Y[i+1]-Y[i];
			tx+=X[i+1]-X[i];
			ok&=valid(ty,tx);
		}
		if(ok) pat++;
	}
	if(pat==1) _P("YES\n");
	else _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}