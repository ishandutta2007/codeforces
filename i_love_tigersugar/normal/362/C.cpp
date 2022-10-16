#include<cstdio>
#define MAX   5005
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typedef((v).begin()) i=(v).begin();i!=(v).end();i++)
int p[MAX];
int s[MAX][MAX];
int n,fst;
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&p[i]);
		p[i]++;
	}
	FOR(i,1,n) FOR(j,1,n)
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(p[i]==j);	
}
int count(int x1,int x2,int y1,int y2) {
	if (x1>x2) return (0);
	if (y1>y2) return (0);
	//printf("\tCount %d %d %d %d is %d\n",x1,x2,y1,y2,s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);	
	return (s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int change(const int &i,const int &j) {
	int ret=0;
	ret+=count(1,i-1,p[j]+1,n)-count(1,i-1,p[i]+1,n);
	ret+=count(1,j-1,p[i]+1,n)-count(1,j-1,p[j]+1,n);	
	if (p[j]>p[i]) ret++;
	//printf("1st %d\n",ret);
	if (p[j]>p[i]) ret+=count(i+1,j-1,p[i]+1,p[j]-1);
	else ret-=count(i+1,j-1,p[j]+1,p[i]-1);
	//printf("Change in %d %d is %d\n",i,j,ret);
	return (ret+fst);
}
void process(void) {
	fst=0;
	FOR(i,1,n) fst+=count(1,i-1,p[i]+1,n);
	//printf("%d\n",fst);
	int min=fst;
	int cnt=0;
	FOR(i,1,n-1) FOR(j,i+1,n) {
		if (min>change(i,j)) {
			min=change(i,j);
			cnt=1;
			continue;
		}
		if (min==change(i,j)) cnt++;
	}
	printf("%d %d",min,cnt);
}
int main(void) {
	init();
	process();
	return 0;
}