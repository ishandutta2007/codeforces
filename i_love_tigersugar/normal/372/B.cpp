#include<cstdio>
#include<cstring>
#define MAX   47
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char a[MAX][MAX];
int s[MAX][MAX];
int le[MAX][MAX][MAX];
int ri[MAX][MAX][MAX];
int sum[MAX][MAX][MAX];
int m,n,q;
int min(int x,int y) {
	if (x<y) return (x); else return (y);
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&q);
	FOR(i,1,m) {
		scanf("%s",a[i]+1);
		FOR(j,1,n) s[i][j]=s[i-1][j]+a[i][j]-48;
	}
}
void precount(void) {
	FOR(i,1,m) FOR(j,i,m) FOR(k,1,n) {
		if (s[j][k]!=s[i-1][k]) {
			le[i][j][k]=0;
			ri[i][j][k]=0;
			continue;
		}
		FOR(d,2,k+1) if (k<d || s[j][k-d+1]!=s[i-1][k-d+1]) {
			le[i][j][k]=d-1;
		//	printf("Left %d %d %d is %d\n",i,j,k,d-1);
			break;
		}
		FOR(d,2,n-k+2) if (k+d-1>n || s[j][k+d-1]!=s[i-1][k+d-1]) {
			ri[i][j][k]=d-1;
		//	printf("Right %d %d %d is %d\n",i,j,k,d-1);
			break;
		}
	}
	FOR(i,1,m) FOR(j,i,m) FOR(k,1,n) {
		if (s[j][k]!=s[i-1][k]) sum[i][j][k]=sum[i][j][k-1];
		else sum[i][j][k]=sum[i][j][k-1]+le[i][j][k];
	}
	
}
void answer(int x1,int y1,int x2,int y2) {	
	int res=0;
	int tmp;
	FOR(top,x1,x2) FOR(bot,top,x2) {
		tmp=sum[top][bot][y2]-sum[top][bot][y1-1];
		if (le[top][bot][y1]>0) tmp-=(le[top][bot][y1]-1)*min(ri[top][bot][y1],y2-y1+1);
	//	printf("TMP %d %d %d\n",top,bot,tmp);
		res+=tmp;
	}
	printf("%d\n",res);
} 
void process(void) {
	int x1,y1,x2,y2;
	REP(i,q) {
		scanf("%d",&x1);
		scanf("%d",&y1);
		scanf("%d",&x2);
		scanf("%d",&y2);
		answer(x1,y1,x2,y2);
	}
}
int main(void) {
#ifdef MYHOME
	freopen("tmp.txt","r",stdin);
#endif
	init();
	precount();
	process();
	return 0;
}