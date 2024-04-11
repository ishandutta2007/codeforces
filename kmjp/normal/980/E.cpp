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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,22> bt;

int N,K;
vector<int> E[1010101];
int id;
int L[1010101],R[1010101],D[1010101],P[1010101];
int lef[1010101];

void dfs(int cur,int pre) {
	L[cur]=id++;
	P[cur]=pre;
	D[cur]=D[pre]+1;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	K=N-K;
	dfs(N,N);
	for(i=N;i>=1;i--) {
		x=bt(L[i]);
		if(D[i]-x<=K) {
			K-=D[i]-x;
			int cur=i;
			FOR(y,D[i]-x) {
				lef[cur]=1;
				bt.add(L[cur],1);
				bt.add(R[cur],-1);
				cur=P[cur];
			}
		}
	}
	for(i=1;i<=N;i++) if(lef[i]==0) _P("%d ",i);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}