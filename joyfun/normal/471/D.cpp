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

const int N = 200005;
int a[N], b[N], jp[N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i - 1] = a[i] - a[i - 1];
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), b[i - 1] = b[i] - b[i - 1];
	int j = 0;
	if (m == 1) {
		printf("%d\n", n);
		return 0;
	}
	n--; m--;
	for (int i = 2; i <= m; i++) {
		while (j && b[j + 1] != b[i]) j = jp[j];
		if (b[j + 1] == b[i]) j++;
		jp[i] = j;
	}
	j = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (j && b[j + 1] != a[i]) j = jp[j];
		if (b[j + 1] == a[i]) j++;
		if (j == m) {
			j = jp[j];
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}