#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
vector<int> g[MAX];
bool stt[MAX][29];
char res[MAX];
bool vst[MAX];
int n;
void loadtree(void) {
	scanf("%d",&n);
	int u,v;
	REP(i,n-1) {		
		scanf("%d",&u);
		scanf("%d",&v);
		g[u].push_back(v);
		g[v].push_back(u);
	//	if (n==100 && i>65) printf("%d %d ",u,v);
	}
}
void visit(const int &u) {
	int v;
	int cnt[29];
	memset(cnt,0,sizeof cnt);
	memset(stt[u],false,sizeof stt[u]);	
	FORE(it,g[u]) {
		v=*it;
		if (!vst[v]) {
			vst[v]=true;			
			visit(v);
			REP(i,26) if (stt[v][i]) cnt[i]++;
		}
	}
	cnt[26]=3;
	REP(lim,27) if (cnt[lim]>1) {	
		FORD(i,lim-1,0) if (cnt[i]==0) {
			res[u]=i+'A';
			REP(j,i) stt[u][j]=(cnt[j]>0);
			stt[u][i]=true;
			return;
		}
		break;
	}	
	printf("Impossible!");
	exit(0);
}
/*void visit(const int &u,int lev) {
	int v;
	REP(i,lev) printf(" "); printf("%d %c\n",u,res[u]);
	FORE(it,g[u]) {
		v=*it;
		if (!vst[v]) {
			vst[v]=true;
			visit(v,lev+1);
		}
	}
}*/
void process(void) {
	vst[1]=true;
	visit(1);
	//memset(vst,false,sizeof vst);
	//vst[1]=true;
	//visit(1,0);	
	printf("%c",res[1]);
	FOR(i,2,n) printf(" %c",res[i]);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	loadtree();
	process();	
	return 0;
}