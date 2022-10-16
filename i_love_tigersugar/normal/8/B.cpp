#include<bits/stdc++.h>
#define MAX   111
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
char s[MAX];
int a[2*MAX][2*MAX];
int c[2*MAX][2*MAX];
int d[2*MAX][2*MAX];
int l;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
ii cur;
ii next(const ii &u,const int &d) {
	return (ii(u.x+dx[d],u.y+dy[d]));
}
void init(void) {
	memset(a,0,sizeof a);
	memset(c,0,sizeof c);
	scanf("%s",s);
	l=strlen(s);
	int i;
	cur=ii(0,0);
	a[MAX][MAX]=1;
	for (i=0;i<l;i=i+1) {
		if (s[i]=='L') cur.x--;
		if (s[i]=='R') cur.x++;
		if (s[i]=='D') cur.y--;
		if (s[i]=='U') cur.y++;
		a[cur.x+MAX][cur.y+MAX]=1;		
	}
}
void BFS(void) {
	queue<ii> q;
	while (!q.empty()) q.pop();
	q.push(ii(0,0));
	c[MAX][MAX]=1;
	int i;
	ii u;
	ii v;
	while (!q.empty()) {
		u=q.front();q.pop();
		if (u==cur) {
			if (d[u.x+MAX][u.y+MAX]<l) printf("BUG");
			else printf("OK");
			return;
		}
		for (i=0;i<4;i=i+1) {
			v=next(u,i);
			if (a[v.x+MAX][v.y+MAX]==1 && c[v.x+MAX][v.y+MAX]==0)			 {
				c[v.x+MAX][v.y+MAX]=1;
				d[v.x+MAX][v.y+MAX]=d[u.x+MAX][u.y+MAX]+1;
				q.push(v);
			}
		}
	}
}
int main(void) {
	init();
	BFS();
	return 0;
}