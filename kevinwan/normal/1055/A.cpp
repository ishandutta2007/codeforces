#include <bits/stdc++.h>

using namespace std;
bool a[1001], b[1001];
int main() {
	int n, s,i;
	scanf("%d%d", &n, &s);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	for (i = 1; i <= n; i++)scanf("%d", b + i);
	if (!a[1]) { printf("NO"); return 0; }
	if (a[s]) { printf("YES"); return 0; }
	if (!b[s]) { printf("NO"); return 0; }
	for (i = s; i <= n; i++)if (a[i] && b[i]) { printf("YES"); return 0; }
	printf("NO");
	getchar(); getchar();
}