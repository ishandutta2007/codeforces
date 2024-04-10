#include <stdio.h>
#include <string.h>
#define MAXL 4050

const int inf = 1000000000;

int al,bl;
int ti,td,tr,te;
char a[MAXL],b[MAXL];

int dp[MAXL][MAXL];
int nexta[MAXL][128],nextb[MAXL][128];

inline int min(int a,int b) { return a<b?a:b; }
inline void relax(int &x,int val) { if(val<x) x=val; }

inline int solve() {
	int i,j,x,y;
	for(j='a';j<='z';j++) {
		nexta[al-1][j]=inf;
		for(i=al-2;i>=0;i--) {
			if(a[i+1]==j) nexta[i][j]=i+1;
			else nexta[i][j]=nexta[i+1][j];
		}
	}
	for(j='a';j<='z';j++) {
		nextb[bl-1][j]=inf;
		for(i=bl-2;i>=0;i--) {
			if(b[i+1]==j) nextb[i][j]=i+1;
			else nextb[i][j]=nextb[i+1][j];
		}
	}
	for(i=0;i<=al;i++)
		for(j=0;j<=bl;j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(i=0;i<=al;i++) {
		for(j=0;j<=bl;j++) {
			// match
			if(i<al&&j<bl&&a[i]==b[j]) relax(dp[i+1][j+1],dp[i][j]);
			// insert
			if(j<bl) relax(dp[i][j+1],dp[i][j]+ti);
			// delete
			if(i<al) relax(dp[i+1][j],dp[i][j]+td);
			// replace
			if(i<al&&j<bl) relax(dp[i+1][j+1],dp[i][j]+tr);
			if(i<al-1&&j<bl-1) {
				// exchange + replace
				if(a[i]==b[j+1]||a[i+1]==b[j])
					relax(dp[i+2][j+2],dp[i][j]+te+tr);
				// exchange + ins
				x=nexta[i][b[j]];
				y=nextb[j][a[i]];
				if(x<inf&&y<inf)
					relax(dp[x+1][y+1],dp[i][j]+td*(x-i-1)+ti*(y-j-1)+te);
				/*
				// exchange + del
				x=nexta[i][b[j]];
				if(x<inf&&j<bl-1&&a[i]==b[j+1])
					relax(dp[x+1][j+2],dp[i][j]+td*(x-i-1)+te);
					*/
			}
		}
	}
	return dp[al][bl];
}

int main(void)
{
	while(scanf("%d %d %d %d",&ti,&td,&tr,&te)==4) {
		scanf("%s",a);
		scanf("%s",b);
		al=strlen(a);
		bl=strlen(b);
		printf("%d\n",solve());
	}
}