#include<cstdio>
int main(void) {
	int sh,sm,th,tm;
	scanf("%d:%d",&sh,&sm);
	scanf("%d:%d",&th,&tm);
	int s=sh*60+sm;
	int t=th*60+tm;
	int d=s-t;
	if (d<0) d=d+1440;
	printf("%02d:%02d",d/60,d%60);
	return 0;
}