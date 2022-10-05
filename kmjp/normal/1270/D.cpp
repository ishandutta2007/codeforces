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

int N,K;
int A[505];
int B[505];

int ask(set<int> V) {
	cout<<"?";
	FORR(v,V) cout<<" "<<v;
	cout<<endl;
	int a,b;
	cin>>a>>b;
	A[a]=b;
	return a;
	
}

void ans(int v) {
	cout<<"! "<<v<<endl;
	exit(0);
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==1) ans(1);
	set<int> S,fixed;
	for(i=1;i<=K;i++) S.insert(i);
	x=ask(S);
	S.clear();
	for(i=1;i<=K+1;i++) if(i!=x) S.insert(i);
	y=ask(S);
	S.clear();
	if(A[x]>A[y]) swap(x,y);
	//cerr<<"!"<<x<<" "<<y<<endl;
	int ret=1;
	for(i=1;i<=K+1;i++) if(i!=x && i!=y) {
		S.clear();
		for(j=1;j<=K+1;j++) if(j!=i) S.insert(j);
		j=ask(S);
		if(j!=x) ret++;
	}
	ans(ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}