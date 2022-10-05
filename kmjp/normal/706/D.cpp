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
char C[202020];
int X[202020];
vector<int> V;
map<int,int> M;

int one[202020][32];
int sz[202020][32];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs(int d,int s,int e) {
	int i;
	if(s==e) return;
	if(d<0) return;
	sz[s][d]=e-s;
	for(i=s;i<e;i++) if(V[i] & (1<<d)) break;
	one[s][d]=i;
	dfs(d-1,s,i);
	dfs(d-1,i,e);
}
int dfs2(int d,int s,int e,int x) {
	int i;
	
	if(e-s==1) return s;
	int zerofirst=(x & (1<<d))>0;
	
	if(zerofirst) {
		if(bt(one[s][d])-bt(s)) return dfs2(d-1,s,one[s][d],x);
		return dfs2(d-1,one[s][d],e,x);
	}
	else {
		if(bt(e)-bt(one[s][d])) return dfs2(d-1,one[s][d],e,x);
		return dfs2(d-1,s,one[s][d],x);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V.push_back(0);
	FOR(i,N) {
		cin>>C[i]>>X[i];
		V.push_back(X[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,V.size()) M[V[i]]=i;
	
	dfs(30,0,V.size());
	
	bt.add(1,1);
	
	FOR(i,N) {
		if(C[i]=='+') bt.add(M[X[i]]+1,1);
		else if(C[i]=='-') bt.add(M[X[i]]+1,-1);
		else {
			int y = dfs2(30,0,V.size(),X[i]);
			cout<<(V[y]^X[i])<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}