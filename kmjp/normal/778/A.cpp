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

string T,P;
int TL,PL;
int A[202020];
int vis[202020];

int ok(int v) {
	
	if(v>TL) return 0;
	ZERO(vis);
	int i;
	FOR(i,v) vis[A[i]-1]++;
	
	int cur=0;
	FOR(i,TL) if(vis[i]==0) {
		if(T[i]==P[cur]) {
			cur++;
			if(cur==PL) return 1;
		}
	}
	return 0;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>P;
	TL=T.size();
	PL=P.size();
	FOR(i,TL) cin>>A[i];
	
	int ret=0;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret += 1<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}