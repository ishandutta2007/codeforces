#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int dx[]={1,1,1,2};
int dy[]={-1,0,1,0};
char a[MAX][MAX];
int n;
void process(void) {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%s",a[i]+1);
	FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='#') REP(k,4) {
		int vx=i+dx[k];
		int vy=j+dy[k];
		if (a[vx][vy]!='#') {
			printf("NO");
			return;
		}
		else a[vx][vy]='.';
	}
	printf("YES");
}
int main(void) {
	process();
	return 0;
}