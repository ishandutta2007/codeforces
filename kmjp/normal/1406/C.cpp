#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
vector<int> E[101010];
int C[101010];
int D[101010];

int dfs(int cur,int pre) {
	C[cur]=1;
	D[cur]=0;
	FORR(e,E[cur]) if(e!=pre) {
		int r=dfs(e,cur);
		D[cur]=max(D[cur],r);
		C[cur]+=r;
	}
	D[cur]=max(D[cur],N-C[cur]);
	return C[cur];
}

int dfs2(int cur,int pre) {
	if(E[cur].size()==1) return cur;
	else {
		FORR(e,E[cur]) if(e!=pre) return dfs2(e,cur);
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0);
		vector<int> V={0};
		for(i=1;i<N;i++) {
			if(D[i]<D[V[0]]) {
				V={i};
			}
			else if(D[i]==D[V[0]]) {
				V.push_back(i);
			}
		}
		
		if(V.size()==1) {
			cout<<(V[0]+1)<<" "<<(E[V[0]][0]+1)<<endl;
			cout<<(V[0]+1)<<" "<<(E[V[0]][0]+1)<<endl;
		}
		else {
			x=dfs2(V[0],V[1]);
			cout<<(x+1)<<" "<<E[x][0]+1<<endl;
			cout<<(V[1]+1)<<" "<<(x+1)<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}