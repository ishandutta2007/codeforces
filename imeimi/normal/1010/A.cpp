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

int n, m;
int a[1001];
int b[1001];

ld process(ld x, int y) {
    return x - (x + m) / y;
}

int check(ld x) {
    for (int i = 1; i <= n; ++i) {
        x = process(x, a[i]);
        if (x < 0) return 0;
        x = process(x, b[i % n + 1]);
        if (x < 0) return 0;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	ld s = 0, e = 1.2e9;
	for (int i = 0; i < 1000; ++i) {
        ld m = (s + e) / 2;
        if (check(m)) e = m;
        else s = m;
	}
	cout.precision(20);
	if (s > 1.1e9) cout << "-1\n";
	else cout << s << '\n';
	return 0;
}