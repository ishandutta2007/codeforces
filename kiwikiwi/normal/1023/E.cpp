#include <bits/stdc++.h>
using namespace std;

int n;
string ans,ans2;
bool query(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
	if (x1 > n || y1 > n || x1 <= 0 || y1 <= 0) return 0;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	char s[20];
	scanf("%s", s);
	if (s[0] == 'Y') return 1;
	else return 0;
}

int main() {
	scanf("%d", &n);
	int x = 1, y = 1;
	for (int i = 2; i <= n; i++) {
		if (query(x + 1, y, n, n) == 1) {
			++x;
			ans.push_back('D');
		} else {
			++y;
			ans.push_back('R');
		}
	}
	x = n, y = n;
	for (int i = 2; i <= n; i++) {
		if (query(x, y - 1, 1, 1) == 1) {
			--y;
			ans2.push_back('R');
		} else {
			--x;
			ans2.push_back('D');
		}
	}
	reverse(ans2.begin(), ans2.end());
	ans += ans2;
	printf("! %s\n", ans.c_str());
}