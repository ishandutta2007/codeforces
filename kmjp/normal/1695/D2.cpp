#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
vector<int> E[202020];
int sum[202020],did[202020],fail[202020];
int ret;
void dfs(int cur,int pre) {
	sum[cur]=did[cur]=fail[cur]=0;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		sum[cur]+=sum[e];
		did[cur]+=did[e]>0;
		if(did[e]==0) fail[cur]++;
	}
	if(fail[cur]>1) {
		did[cur]+=fail[cur]-1;
		sum[cur]+=fail[cur]-1;
	}
}
void dfs2(int cur,int pre,int ps,int pd) {
	if(cur!=pre) {
		if(fail[cur]>1) {
			did[cur]-=fail[cur]-1;
			sum[cur]-=fail[cur]-1;
		}
		sum[cur]+=ps;
		did[cur]+=pd>0;
		if(pd==0) fail[cur]++;
		if(fail[cur]>1) {
			did[cur]+=fail[cur]-1;
			sum[cur]+=fail[cur]-1;
		}
	}
	if(E[cur].size()==1) ret=min(ret,sum[cur]+1);
	FORR(e,E[cur]) if(e!=pre) {
		int ps=sum[cur],pd=did[cur],pf=fail[cur];
		
		if(fail[cur]>1) {
			did[cur]-=fail[cur]-1;
			sum[cur]-=fail[cur]-1;
		}
		sum[cur]-=sum[e];
		did[cur]-=did[e]>0;
		if(did[e]==0) fail[cur]--;
		if(fail[cur]>1) {
			did[cur]+=fail[cur]-1;
			sum[cur]+=fail[cur]-1;
		}
		dfs2(e,cur,sum[cur],did[cur]);
		sum[cur]=ps;
		did[cur]=pd;
		fail[cur]=pf;
	}
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
		
		if(N==1) {
			cout<<0<<endl;
			continue;
		}
		ret=202020;
		FOR(i,N) if(E[i].size()==1) {
			dfs(i,i);
			dfs2(i,i,0,0);
			break;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}