#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, x , y;
i64 sx, sy;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		sx += x;
		sy += y;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		sx += x;
		sy += y;
	}
	printf("%lld %lld\n", sx / n, sy / n);
}