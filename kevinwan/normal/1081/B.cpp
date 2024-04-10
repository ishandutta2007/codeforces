#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
int a[1000000], c[1000000], b[1000000], at[1000000], k[1000000];
void die() { printf("Impossible"); getchar(); getchar(); exit(0); }
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i), a[i] = n - a[i], c[a[i]]++;
	int cnt = 1;
	for (i = 1; i <= n; i++) {
		if (c[i] % i)die();
		if (c[i])at[i] = cnt++;
	}
	for (i = 0; i < n; i++) {
		b[i] = at[a[i]];
		k[a[i]]++;
		if (k[a[i]] % a[i] == 0) {
			if (k[a[i]] != c[a[i]])at[a[i]] = cnt++;
		}
	}
	printf("Possible\n");
	for (i = 0; i < n; i++)printf("%d ", b[i]);
	getchar(); getchar();
}