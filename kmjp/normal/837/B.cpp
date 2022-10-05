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
int L[3],R[3],U[3],D[3];
int num[3];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) {
		L[i]=U[i]=101;
		R[i]=D[i]=-1;
	}
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S;
		FOR(x,W) {
			if(S[x]=='R') i=0;
			if(S[x]=='G') i=1;
			if(S[x]=='B') i=2;
			L[i]=min(L[i],x);
			R[i]=max(R[i],x);
			U[i]=min(U[i],y);
			D[i]=max(D[i],y);
			num[i]++;
		}
	}
	
	FOR(x,3) FOR(y,3) {
		if(num[x]!=num[y]) return _P("NO\n");
		if(R[x]-L[x]!=R[y]-L[y]) return _P("NO\n");
		if(D[x]-U[x]!=D[y]-U[y]) return _P("NO\n");
	}
	if((R[0]-L[0]+1)*(D[0]-U[0]+1)!=num[0]) return _P("NO\n");
	_P("YES\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}