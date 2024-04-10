#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x, s=0x3f3f3f3f, l=0,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &x), s = min(s, x), l = max(l, x);
	printf("%d", l - s + 1 - n);
	getchar(); getchar();
}