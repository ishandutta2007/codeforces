#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
bool g[MAX][MAX];
int n,k;
vector<int> v1,v2;
void init(void) {
	scanf("%d",&k);
	n=2;
	v1.push_back(1);
	v2.push_back(2);
}
void addedge(int u,int v) {
	g[u][v]=true;
	g[v][u]=true;
}
void createnode(int x,vector<int> &v) {	
	v.clear();
	REP(i,x) {
		n++;
		assert(n<=1000);
		v.push_back(n);
	}
}
void filledge(const vector<int> &a,const vector<int> &b) {
	FORE(it,a) FORE(jt,b) addedge(*it,*jt);
}
void addlayer(int a,int b) {
	vector<vector<int> > v;
	v.clear();
	v.push_back(vector<int>());
	createnode(a,v[0]);
	REP(i,9) {
		v.push_back(vector<int>());
		if (i<b) createnode(10,v[v.size()-1]);
		else createnode(1,v[v.size()-1]);
	}
	REP(i,v.size()-1) filledge(v[i],v[i+1]);
	filledge(v1,v[0]);
	filledge(v2,v[v.size()-1]);
}
void process(void) {
	int t=0;
	while (k>0) {
		int x=k%10;
		k=k/10;
		addlayer(x,t);
		t++;
	}
	printf("%d\n",n);
	FOR(i,1,n) {
		FOR(j,1,n) {
			if (g[i][j]) printf("Y"); else printf("N");			
		}
		printf("\n");
	}	
}
int main(void) {
	init();
	process();
	return 0;
}