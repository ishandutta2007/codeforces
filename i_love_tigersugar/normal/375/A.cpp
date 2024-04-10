#include<cassert>
#include<cstdio>
#include<cstring>
#define MAX   1000100
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
const int chs[]={1869,1968,1689,6198,1698,1986,1896};
char a[MAX];
int ans[MAX];
int cnt[13];
int len;
void init(void) {
	REP(i,7) assert((chs[i]-i)%7==0);
	scanf("%s",a);
	len=strlen(a);
	REP(i,len) cnt[a[i]-48]++;
	int id=0;
	int mod=0;
	int mul=1;
	FOR(i,1,9) {
		int tmp=cnt[i];
		if (i==1 || i==6 || i==8 || i==9) tmp--;
		REP(j,tmp) {
			ans[id]=i;
			id++;
			mod=(mod+i*mul)%7;
			mul=(mul*10)%7;
		}		
	}
	mod=(mod*10000)%7;
	FORD(i,id-1,0) printf("%d",ans[i]);
	if (mod==0) printf("%d",chs[0]);
	else printf("%d",chs[7-mod]);
	REP(i,cnt[0]) printf("0");
}
int main(void) {
	init();
	return 0;
}