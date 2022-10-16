#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
const char s[]="C.";
int main(void) {
	int n;
	scanf("%d",&n);
	printf("%d\n",n*n/2+n%2);
	FOR(i,1,n) {
		FOR(j,1,n) printf("%c",s[(i+j)%2]);
		printf("\n");
	}
}