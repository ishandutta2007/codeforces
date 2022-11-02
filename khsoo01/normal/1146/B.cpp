#include<bits/stdc++.h>
using namespace std;

int n;
char a[200005], b[200005];

int main()
{
	scanf("%s",a+1);
	n = strlen(a+1);
	for(int i=1,j=0;i<=n;i++) {
		if(a[i] != 'a') {
			b[++j] = a[i];
		}
		if(i + j != n) continue;
		bool F = false;
		for(int k=1;k+i<=n;k++) {
			if(b[k] != a[k+i]) {
				F = true;
				break;
			}
		}
		if(F) puts(":(");
		else {
			for(int k=1;k<=i;k++) {
				putchar(a[k]);
			}
			puts("");
		}
		return 0;
	}
	puts(":(");
}