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

vector<int> EV[201010];
int vis[201010];
int NV[201010];
vector<int> D;
ll ret;

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int depth) {
	D.push_back(depth);
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) dfs3(e,cur,depth+1);
}

void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	dfs(cur,-1);
	int center=dfs2(cur,-1,TNV);
	
	ll num[5]={};
	ll tot[5]={};
	num[0]=1;
	int i;
	
	FORR(e,EV[center]) if(vis[e]==0) {
		D.clear();
		dfs3(e,center,1);
		FORR(r,D) {
			FOR(i,K) {
				ret += num[i]*(r/K);
				ret += tot[i];
				if(r%K+i>0 && r%K+i<=K) ret += num[i];
				else if((r%K+i)>K) ret += 2*num[i];
			}
		}
		FORR(r,D) num[r%K]++, tot[r%K]+=r/K;
	}
	
	vis[center]=1;
	FORR(e,EV[center]) if(vis[e]==0) split(e,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		EV[x-1].push_back(y-1);
		EV[y-1].push_back(x-1);
	}
	
	split(0,0);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}