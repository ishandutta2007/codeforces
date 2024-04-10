#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c;
		scanf ("%d%d%d%d%d", &b, &p, &f, &h, &c);
		int mb = b / 2;
		if (h < c) swap(h, c), swap(p, f);
		int ans = 0;
		if (p >= mb) {
			ans += mb * h;
			printf ("%d\n", ans);
			continue;
		}
		ans += p * h, mb -= p;
		if (f >= mb) ans += mb * c;
		else ans += f * c;
		printf ("%d\n", ans);
	}
	return 0;
}