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
ll X[101010],Y[101010];

int colinear(int a,int b,int c) {
	if(a==b || b==c || a==c) return 1;
	ll dx1=X[b]-X[a];
	ll dy1=Y[b]-Y[a];
	ll dx2=X[c]-X[a];
	ll dy2=Y[c]-Y[a];
	
	return (dx1*dy2==dx2*dy1);
	
}

int test(int a,int b) {
	vector<int> L;
	int i;
	FOR(i,N) if(colinear(a,b,i)==0) L.push_back(i);
	
	for(i=2;i<L.size();i++) if(colinear(L[0],L[1],L[i])==0) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	if(N<=2) return _P("YES\n");
	
	// 0-1
	if(test(0,1)) return _P("YES\n");
	if(test(0,2)) return _P("YES\n");
	if(test(1,2)) return _P("YES\n");
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}