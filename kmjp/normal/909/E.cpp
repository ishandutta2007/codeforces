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

int N,M;
int C[101010];
vector<int> E[101010];
int in[101010];
int did[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) scanf("%d",&C[i]);
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		E[y].push_back(x);
		in[x]++;
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	int ret=0;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(C[x]==1) did[x]=max(did[x],1);
		FORR(e,E[x]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
			did[e]=max(did[e],did[x]+(C[x]==0&&C[e]==1));
			
		}
		ret=max(ret,did[x]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}