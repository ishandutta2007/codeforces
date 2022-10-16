#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX][MAX];
int n,m,k;
inline void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d%d%d",&m,&n,&k);
	REP(i,m) REP(j,n) scanf("%d",&a[i][j]);	
}
int mindiff(int x,int y) {
	int res1=0;
	int res2=0;
	REP(i,m) if (a[i][x]!=a[i][y]) res1++; else res2++;
	return (min(res1,res2));
}
int minstt(int x,int s) {
	int res1=0;
	int res2=0;
	REP(i,n) if (a[x][i]^((s>>i)&1)) res1++; else res2++;
	return (min(res1,res2));
}
void bigcase(void) {
	int res=k+1;
	REP(i,n) {
		int sum=0;
		REP(j,n) sum+=mindiff(i,j);
		minimize(res,sum);
	}
	printf("%d",res>k?-1:res);
}
void smallcase(void) {
	int res=k+1;
	REP(i,1<<n) {
		int sum=0;
		REP(j,m) sum+=minstt(j,i);
		minimize(res,sum);
	}
	printf("%d",res>k?-1:res);
}
int main(void) {
	init();
	if (n<=k) smallcase(); else bigcase();
	return 0;
}