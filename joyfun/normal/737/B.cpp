#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n, a, b, k;
char s[N];
int ans[N], an;

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", s + 1);
	int cnt = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') cnt++;
		else {
			tot += cnt / b;
			cnt = 0;
		}
	}
	tot += cnt / b;
	an = 0;
	cnt = 0;
	tot -= (a - 1);
	for (int i = 1; i <= n; i++) {
		if (tot <= 0) break;
		if (s[i] == '0') {
			cnt++;
			if (cnt >= b) {
				ans[an++] = i;
				cnt = 0;
				tot--;
			}
		} else {
			cnt = 0;
		}
	}
	printf("%d\n", an); for (int i = 0; i < an; i++) printf("%d ", ans[i]);
	return 0;
}