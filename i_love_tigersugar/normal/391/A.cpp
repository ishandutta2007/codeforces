#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
char a[111];
int n;
int main(void) {
	scanf("%s",a+1);
	n=strlen(a+1);
	int j=1;
	int cnt=0;
	FOR(i,1,n) {
		if (a[i]!=a[j]) {
			if ((i-j)%2==0) cnt++;
			j=i;
		}		
	}
	if ((n+1-j)%2==0) cnt++;
	printf("%d",cnt);
	return 0;
}