#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int inf = 1e9;
int n, m;
int a[2001];
int ma[2001];
int b[2001];
int mb[2001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i], ma[i] = inf;
	for (int i = 1; i <= m; ++i) cin >> b[i], mb[i] = inf;
	for (int i = 1; i <= m; ++i) {
        int sum = 0;
        for (int j = i; j <= m; ++j) {
            sum += b[j];
            mb[j - i + 1] = min(mb[j - i + 1], sum);
        }
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = i; j <= n; ++j) {
            sum += a[j];
            ma[j - i + 1] = min(ma[j - i + 1], sum);
        }
	}
	int x;
	cin >> x;
	for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((llong)ma[i] * mb[j] <= x) ans = max(ans, i * j);
        }
	}
	printf("%d\n", ans);
	return 0;
}