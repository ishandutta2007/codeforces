#include <stdio.h>
#define MAXN 100050

const int inf=1000000000;

int an,bn,sol;
int a[MAXN],b[MAXN];
int adst[MAXN],bdst[MAXN];
int marked[MAXN];

inline int abs(int x) { return x>=0?x:0-x; }
inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline bool connect(int j,int d) {
//	printf("[%d %d %d]\n",j,d,bdst[j]);
	if(d>bdst[j]) return 0;
	if(d<bdst[j]) {
		bdst[j]=d;
		if(marked[j]) return 0;
		sol-=marked[j];
		sol++;
		marked[j]=1;
		return 1;
	}//printf("%d %d!",j,d);
	marked[j]++;
	sol++;
	return 1;
}

inline int solve() {
	int i,j,d1,d2;
	for(i=0;i<bn;i++) {
		marked[i]=0;
		bdst[i]=inf;
	}
	j=0;
	sol=0;
	for(i=0;i<an;i++) {
		while(j<bn&&b[j]<=a[i]) j++;
//		adst[i]=inf;
//		if(j) adst[i]=min(adst[i],abs(a[i]-b[j-1]));
//		if(j<bn) adst[i]=min(adst[i],abs(a[i]-b[j]));
		if(j) d1=abs(a[i]-b[j-1]);
		else d1=inf;
		if(j<bn) d2=abs(a[i]-b[j]);
		else d2=inf;
//		printf("(%d: %d %d)\n",i,d1,d2);
		if(d1<d2) connect(j-1,d1);
		else if(d1>d2) connect(j,d2);
		else {//printf("<%d>",i);
			if(!connect(j-1,d1)) connect(j,d1);
		}
/*		if(d1!=inf && (d1<d2 || d1==d2&&(!marked[j-1]||bdst[j-1]==d1))) {
			if(!marked[j-1]||bdst[j-1]==d1) {
				marked[j-1]=1;
				bdst[j-1]=d1;
				c++;
//				printf("<%d %d>\n",a[i],b[j]);
			}
		} else if(d2!=inf && d1>=d2) {
			bdst[j]=d2;
			if(!marked[j]) {
				c++;
				marked[j]=1;
//				printf("<%d %d>\n",a[i],b[j]);
			}
		}*/
	}
	return an-sol;
}

int main(void)
{
	int i,j;
	while(scanf("%d %d %*d %*d",&an,&bn)==2) {
		for(i=0;i<an;i++)
			scanf("%d",a+i);
		for(i=0;i<bn;i++)
			scanf("%d",b+i);
		printf("%d\n",solve());
	}
	return 0;
}