#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
const int inf = 0x3f3f3f3f;
int n, a[N], p[N], s[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n <= 2) printf("%d\n", n);
	else {
		for (int i = 1; i <= n; i++) {
			if (a[i] > a[i - 1]) p[i] = p[i - 1] + 1;
			else p[i] = 1;
		}
		for (int i = n; i >= 1; i--) {
			if (a[i] < a[i + 1]) s[i] = s[i + 1] + 1;
			else s[i] = 1;
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
			ans = max(ans, p[i] + 1);
		for (int i = 2; i <= n; i++)
			ans = max(ans, s[i] + 1);
		for (int i = 1; i <= n - 2; i++) {
			if (a[i] + 1 < a[i + 2]) ans = max(ans, p[i] + s[i + 2] + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}