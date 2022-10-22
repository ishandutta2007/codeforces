#include <bits/stdc++.h>
using namespace std;

int s[10000];
int main() {
	int n,i,a,b,c,d;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		s[i] = a + b + c + d;
	}
	c=0;
	for (i = 1; i < n; i++)if (s[i] > s[0])c++;
	printf("%d", c + 1);
	getchar(); getchar();
}