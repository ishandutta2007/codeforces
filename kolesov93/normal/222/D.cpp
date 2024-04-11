#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int N = 100111;

int a[N], b[N];
int n, x;

int check(int* a, int* b) {
	int ans = 0;

	int match = n - 1;
	while (match && a[n - 1] + b[match - 1] >= x) {
		--match;
	}

	for (int i = n - 1; i >= 0; --i) {
		while (match != n && a[i] + b[match] < x) {
			++match;
		}

		if (match == n) break;

		++ans;
		++match;
	}

	return ans;
}

int main() {
	//freopen("in", "r", stdin);

	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	

	sort(a, a + n);
	sort(b, b + n);	

	cout << "1 " << max(check(a, b), check(b, a)) << endl;

	return 0;
}