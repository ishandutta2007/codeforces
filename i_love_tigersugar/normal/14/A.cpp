#include<bits/stdc++.h>
#define MAX   57
char a[MAX][MAX];
int m,n;
int l,r,t,b;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void process(void) {
	int i,j;
	scanf("%d",&m);
	scanf("%d",&n);
	for (i=0;i<m;i=i+1) scanf("%s",a[i]);
	l=n;r=-1;
	t=m;b=-1;
	for (i=0;i<m;i=i+1)
		for (j=0;j<n;j=j+1)
			if (a[i][j]=='*') {
				minimize(t,i);
				minimize(l,j);
				maximize(b,i);
				maximize(r,j);
			}
	for (i=t;i<=b;i=i+1) {		
		for (j=l;j<=r;j=j+1) printf("%c",a[i][j]);
		printf("\n");
	}
}	
int main(void) {
	process();
	return 0;
}