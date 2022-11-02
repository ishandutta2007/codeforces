#include <stdio.h>
#include <string.h>
#define MAXL 105
#define MAXK 27

int pl,sl,k;
char zz;
char p[MAXL],occ[MAXL];
char s[MAXL];

bool dp[MAXL][MAXL];
int predj[MAXL][MAXL];
char predc[MAXL][MAXL];

int pre[MAXL];
inline void prekmp(char *p,int pl) {
	int i,x;
	x=-1; // match to which position
	pre[0]=-1;
	for(i=1;i<pl;i++) {
		while(x>=0&&p[x+1]!=p[i])
			x=pre[x];
		if(p[x+1]==p[i]) x++;
		pre[i]=x;
	}
}
/*inline void matchkmp(char *s,int sl,char *p,int pl) {
	int i,x;
	x=-1; // match to which position
	for(i=0;i<sl;i++) {
		while(x>=0&&p[x+1]!=s[i])
			x=pre[x];
		if(p[x+1]==s[i]) x++;
		match[i]=x+1;
		if(match[i]==pl) x=pre[x];
	}
}*/

inline int match(int x,char c) {
	while(x>=0&&p[x+1]!=c)
		x=pre[x];
	if(p[x+1]==c) x++;
	return x;
}

inline bool solve() {
	int i,j,x,nx;
	char c;
	bool occbl;
	memset(s,0,sizeof(s));
	for(i=0;i<sl-pl+1;i++) {
		if(occ[i]=='1') {
			for(j=0;j<pl;j++) {
				if(s[i+j]&&s[i+j]!=p[j]) return 0;
				s[i+j]=p[j];
			}
		}
	}
	prekmp(p,pl);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<sl;i++) {
		for(j=0;j<=pl;j++) {
			if(!dp[i][j]) continue;
			x=j-1;
			if(i<pl-1) occbl=0;
			else occbl=(occ[i-pl+1]=='1'?1:0);
			if(s[i]) {
				nx=match(x,s[i]);
				if(nx+1==pl&&!occbl) continue;
				if(nx+1<pl&&occbl) continue;
				if(nx+1==pl) nx=pre[nx];
				dp[i+1][nx+1]=1;
				predj[i+1][nx+1]=j;
				predc[i+1][nx+1]=s[i];
			} else {
				for(c='a';c<=zz;c++) {
					nx=match(x,c);
					if(nx+1==pl&&!occbl) continue;
					if(nx+1<pl&&occbl) continue;
					if(nx+1==pl) nx=pre[nx];
					dp[i+1][nx+1]=1;
					predj[i+1][nx+1]=j;
					predc[i+1][nx+1]=c;
				}
			}
		}
	}
	i=sl;
	for(j=0;j<=pl;j++)
		if(dp[sl][j]) break;
	if(j>pl) return 0;
	while(i) {
		s[i-1]=predc[i][j];
		j=predj[i][j];
		i--;
	}
	s[sl]='\0';
	puts(s);
	return 1;
}

int main(void)
{
	int i;
	while(scanf("%d %d",&sl,&k)==2) {
		zz='a'+k-1;
		scanf("%s",p);
		pl=strlen(p);
		scanf("%s",occ);
		if(!solve()) puts("No solution");
	}
}