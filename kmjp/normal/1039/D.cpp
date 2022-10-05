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
vector<int> E[101010],V2;
int D[101010];
vector<pair<int,int>> V;
int ret[101010];
int cand[101010][2];

void dfs(int cur,int pre,int depth) {
	D[cur]=depth;
	V.push_back({depth,cur});
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,depth+1);
}

int num(int d) {
	int ret=0;
	
	FORR(v,V) {
		int cur=v.second;
		cand[cur][0]=cand[cur][1]=0;
		FORR(e,E[cur]) if(D[e]>D[cur] && cand[e][0]>=0) {
			int c=cand[e][0];
			if(c>=cand[cur][0]) {
				cand[cur][1]=cand[cur][0];
				cand[cur][0]=c;
			}
			else cand[cur][1]=max(cand[cur][1],c);
		}
		
		if(cand[cur][0]+cand[cur][1]+1>=d) {
			ret++;
			cand[cur][0]=-1;
		}
		else {
			cand[cur][0]++;
		}
	}
	return ret;
}

void dfs2(int L,int R) {
	if(L+1>=R) return;
	if(ret[L]==ret[R]) {
		for(int i=L+1;i<R;i++) ret[i]=ret[L];
		return;
	}
	int M=(L+R)/2;
	ret[M]=num(M);
	dfs2(L,M);
	dfs2(M,R);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0,0);
	sort(ALL(V));
	reverse(ALL(V));
	
	ret[1]=N;
	ret[N]=num(N);
	dfs2(1,N);
	for(i=1;i<=N;i++) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}