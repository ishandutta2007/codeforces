#include<bits/stdc++.h>
#define MAX   1000100
char s[MAX];
char inp[MAX];
int len[MAX];
int f[MAX][3];
int n,nc;
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void init(void) {
	int i,j,k;
	scanf("%s",inp);
	n=strlen(inp);
	for (k=1;k<n;k=k+1)
		if (inp[k]!=inp[k-1]) break;
	j=k;
	i=0;
	do {
		s[i]=inp[j];
		i++;
		j=(j+1)%n;		
	}
	while (j!=k);
	assert(strlen(s)==n);
	assert(s[0]!=s[n-1]);
}
void chain(void) {
	int i,j;
	j=0;
	for (i=1;i<n;i=i+1)
		if (s[i]!=s[j]) {
			nc++;
			len[nc]=i-j;
			j=i;
		}
	nc++;
	len[nc]=n-j;
}
int dp(const int &t) {
	memset(f,-1,sizeof f);
	f[1][t]=t;
	int i,j;
	for (i=1;i<nc;i=i+1)
		for (j=0;j<2;j=j+1)
			if (f[i][j]>=0) {
				maximize(f[i+1][0],f[i][j]);
				if ((j==0 || len[i+1]>1) && (i+1<nc || t==0 || len[1]>1)) maximize(f[i+1][1],f[i][j]+1);
			}
	return (max(f[nc][0],f[nc][1]));
}
void print(void) {
	printf("%d",max(dp(0),dp(1)));
}
int main(void) {
	init();
	chain();
	print();
	return 0;
}