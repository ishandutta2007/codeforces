#include<cstdio>
#include<queue>
#include<vector>
#define MAX   111
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
vector<int> g[MAX];
vector<ii> v;
int n;
int c[MAX];
void BFS(int s,int f) {
	queue<int> q;
	while (!q.empty()) q.pop();
	int i,p;
	for (i=1;i<=v.size();i=i+1) c[i]=0;
	c[s]=1;
	q.push(s);
	while (!q.empty()) {
		p=q.front(); q.pop();
		if (p==f) {
			printf("YES\n");
			return;
		}
		for (i=0;i<g[p].size();i=i+1) 
			if  (c[g[p][i]]==0) {
				c[g[p][i]]=1;
				q.push(g[p][i]);
			}
	}
	printf("NO\n");
}
void add(int a,int b) {
	int i;
	v.push_back(ii(a,b));
	for (i=0;i<v.size()-1;i=i+1) {
		if ((a<v[i].x && v[i].x<b) || (a<v[i].y && v[i].y<b)) g[i+1].push_back(v.size());
		if ((v[i].x<a && a<v[i].y) || (v[i].x<b && b<v[i].y)) g[v.size()].push_back(i+1);
	}		
}
void process(void) {
	scanf("%d",&n);
	int i,t,a,b;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		scanf("%d",&a);
		scanf("%d",&b);
		if (t==1) add(a,b);
		else BFS(a,b);
	}
}
int main(void) {
	process();
	return 0;
}