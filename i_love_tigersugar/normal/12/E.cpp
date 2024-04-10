#include<bits/stdc++.h>
#define MAX   1010
int cur[MAX];
int res[MAX][MAX];
int n;
void process(void) {	
	scanf("%d",&n);
	int i,j,t;
	for (i=1;i<=n;i=i+1) cur[i]=i;
	for (i=1;i<=n;i=i+1) res[i][i]=1;
	for (i=1;i<=n;i=i+1) {		
		t=cur[2];
		for (j=2;j<n;j=j+1) cur[j]=cur[j+1];
		cur[n]=t;
		for (j=1;j<=n;j=j+1)
			res[cur[j]][cur[n+1-j]]=i;
	}
	for (i=1;i<=n;i=i+1)
		for (j=1;j<=n;j=j+1) {
			printf("%d",res[i][j]-1);
			if (j<n) printf(" ");
			else printf("\n");
		}
}
int main(void) {
	process();
	return 0;
}