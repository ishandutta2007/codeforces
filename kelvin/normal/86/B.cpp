#include <stdio.h>
#define MAXL 1050

const int adj[4][2]={1,0, 0,1, -1,0, 0,-1};

int rn,cn;
char g[MAXL][MAXL];

int pred[MAXL][MAXL][2],sub[MAXL][MAXL];
int visited[MAXL][MAXL]={0},visid=0;

inline bool inboard(int r,int c) {
	return r>=0&&r<rn&&c>=0&&c<cn;
}
inline bool valid(int r,int c) {
	return r>=0&&r<rn&&c>=0&&c<cn&&g[r][c]=='.';
}

void dfs(int r,int c,int pr,int pc) {
	int i,nr,nc;
	visited[r][c]=visid;
	sub[r][c]=1;
	pred[r][c][0]=pr;
	pred[r][c][1]=pc;
	for(i=0;i<4;i++) {
		nr=r+adj[i][0];
		nc=c+adj[i][1];
		if(!valid(nr,nc)) continue;
		if(visited[nr][nc]==visid) continue;
		dfs(nr,nc,r,c);
		sub[r][c]+=sub[nr][nc];
	}
}

int filln;
int tar[10][2];
bool used[128];

inline void spray() {
	int i,t,r,c,nr,nc;
//	putas("spray");
/*	printf("<%d> \n",filln);
	for(i=0;i<filln;i++)
		printf("%d %d\n",tar[i][0],tar[i][1]);*/
	for(i='0';i<='9';i++)
		used[i]=0;
	for(i=0;i<filln;i++) {
		r=tar[i][0];
		c=tar[i][1];
		for(t=0;t<4;t++) {
			nr=r+adj[t][0];
			nc=c+adj[t][1];
			if(!inboard(nr,nc)) continue;
			if(g[nr][nc]=='#'||g[nr][nc]=='.') continue;
			used[g[nr][nc]]=1;
		}
	}
	for(t='0';t<='9'&&used[t];t++);
	for(i=0;i<filln;i++) {
		r=tar[i][0];
		c=tar[i][1];
		g[r][c]=t;
	}
}

void walk(int r,int c,int pr,int pc) {
	int i,nr,nc;
	filln=0;
	if(pr>=0) {
		tar[filln][0]=pr;
		tar[filln][1]=pc;
		filln++;
	}
	for(i=0;i<4;i++) {
		nr=r+adj[i][0];
		nc=c+adj[i][1];
		if(!valid(nr,nc)) continue;
		if(pred[nr][nc][0]!=r||pred[nr][nc][1]!=c) continue;
		if(sub[nr][nc]==1) {
			tar[filln][0]=nr;
			tar[filln][1]=nc;
			filln++;
		}
	}
	if(filln) {
		tar[filln][0]=r;
		tar[filln][1]=c;
		filln++;
		spray();
		for(i=0;i<4;i++) {
			nr=r+adj[i][0];
			nc=c+adj[i][1];
			if(!valid(nr,nc)) continue;
			if(pred[nr][nc][0]!=r||pred[nr][nc][1]!=c) continue;
			walk(nr,nc,-1,-1);
		}
	} else {
		bool flag=0;
		for(i=0;i<4;i++) {
			nr=r+adj[i][0];
			nc=c+adj[i][1];
			if(!valid(nr,nc)) continue;
			if(pred[nr][nc][0]!=r||pred[nr][nc][1]!=c) continue;
			if(flag) walk(nr,nc,-1,-1);
			else {
				walk(nr,nc,r,c);
				flag=1;
			}
		}
	}
}

inline bool fill(int r,int c) {
	int i,nr,nc;
	for(i=0;i<4;i++) {
		nr=r+adj[i][0];
		nc=c+adj[i][1];
		if(valid(nr,nc)) break;
	}
//	printf("<%d %d>\n",r,c);
	if(i==4) return 0;
	++visid;
	dfs(r,c,-1,-1);
	walk(r,c,-1,-1);
	return 1;
}

inline bool solve() {
	int i,j;
	for(i=0;i<rn;i++) {
		for(j=0;j<cn;j++) {
			if(g[i][j]=='#') continue;
			if(g[i][j]=='.') {
				if(!fill(i,j)) return 0;
			}
		}
	}
	for(i=0;i<rn;i++)
		puts(g[i]);
	return 1;
}

int main(void)
{
	int i,j;
	while(scanf("%d %d",&rn,&cn)==2) {
		for(i=0;i<rn;i++)
			scanf("%s",g[i]);
		if(!solve()) puts("-1");
	}
}