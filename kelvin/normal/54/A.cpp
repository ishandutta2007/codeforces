#include <stdio.h>
#define MAXN 400

int n,k;
bool ish[MAXN]={0};

inline int solve() {
	int i,c=k-1,s=0;
	for(i=1;i<=n;i++) {
		if(ish[i]||c==0) {
			s++;
			c=k;
		}
		c--;
	}
	return s;
}

int main(void)
{
	int i,c,x;
	scanf("%d %d",&n,&k);
	scanf("%d",&c);
	while(c--) {
		scanf("%d",&x);
		ish[x]=1;
	}
	printf("%d\n",solve());
}