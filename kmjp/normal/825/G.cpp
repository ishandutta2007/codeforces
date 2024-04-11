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

int N,Q;
vector<int> E[1000005];
int mi[1000005];

int dfs(int cur,int pre) {
	mi[cur]=min(cur+1,mi[pre]);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

int mimi;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	scanf("%d%d",&x,&y);
	y%=N;
	mimi=mi[y]=y+1;
	dfs(y,y);
	
	int last=0;
	FOR(i,Q-1) {
		int T,Z,X;
		scanf("%d%d",&T,&Z);
		X=(Z+last)%N;
		if(T==1) {
			mimi=min(mimi,mi[X]);
		}
		else {
			last=min(mimi,mi[X]);
			_P("%d\n",last);
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