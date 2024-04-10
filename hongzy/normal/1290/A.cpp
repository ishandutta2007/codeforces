#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 3505;
int n, m, k, a[N], ans[N][N];
//ans[l][fixl = x]
int main() {
	int test; scanf("%d", &test);
	while(test --) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; i ++) scanf("%d", a + i);
		k = min(k, m - 1);
		for(int l = 0; l <= m - 1 - k; l ++) {
			for(int fl = 0; fl <= k; fl ++) {
				int x = l + fl + 1;
				int y = n - (m - 1 - k - l) - (k - fl);
				ans[l][fl] = max(a[x], a[y]);
			}
		}
		int res = 0;
		for(int i = 0; i <= k; i ++) {
			int minv = 2e9;
			for(int j = 0; j <= m - 1 - k; j ++) {
				minv = min(minv, ans[j][i]);
			}
			if(minv > res) res = minv;
		}
		printf("%d\n", res);
	}
	return 0;
}