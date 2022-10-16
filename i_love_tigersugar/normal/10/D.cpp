#include<bits/stdc++.h>
#define MAX   505
int a[MAX];
int b[MAX];
int f[MAX][MAX];
int t[MAX][MAX];
int m,n;
int seq[MAX];
void init(void) {
	int i;
	scanf("%d",&m);		
	for (i=1;i<=m;i=i+1) scanf("%d",&a[i]);
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) scanf("%d",&b[i]);
}
void optimize(void) {
	int i,j,k;
	for (i=1;i<=m;i=i+1) {
		f[i][0]=0;
		for (j=1;j<=n;j=j+1) {
			if (a[i]!=b[j]) {
				f[i][j]=f[i][j-1];
				t[i][j]=t[i][j-1];
			}
			else {
				f[i][j]=1;
				for (k=1;k<i;k=k+1)
					if (a[k]<a[i] && f[k][j-1]+1>f[i][j]) {
						f[i][j]=f[k][j-1]+1;
						t[i][j]=k;
					}
			}
		}
	}
}
void trace(void) {
	int i,j,k,c;
	c=-1;
	for (i=1;i<=m;i=i+1)
		if (c<f[i][n]) {
			c=f[i][n];
			k=i;
		}
	printf("%d\n",c);
	i=k;
	j=n;
	k=0;
	while (true) {
		if (f[i][j]==0) break;
		if (a[i]==b[j]) {
			k++;
			seq[k]=a[i];
			i=t[i][j];
		}
		j--;		
	}
	for (i=c;i>=1;i=i-1) {
		printf("%d",seq[i]);
		if (i>1) printf(" ");
	}
}
int main(void) {
	init();
	optimize();
	trace();
	return 0;
}