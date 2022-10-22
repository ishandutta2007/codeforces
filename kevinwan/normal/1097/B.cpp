#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
bitset<7201> idk;
int main() {
	idk[3600] = 1;
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		idk = (idk << x) | (idk >> x);
	}
	for (i = 0; i <= 7200; i += 360) {
		if (idk[i]) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}