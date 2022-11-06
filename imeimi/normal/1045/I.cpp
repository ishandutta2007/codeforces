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

int n;
char in[1000001];
int a[100000];
map<int, int> cnt;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> in;
        for (int j = 0; in[j]; ++j) {
            a[i] ^= 1 << (in[j] - 'a');
        }
        ++cnt[a[i]];
	}
	llong ans = 0;
	for (int i = 0; i < n; ++i) {
        ans += cnt[a[i]] - 1;
        for (int j = 0; j < 26; ++j) {
            ans += cnt[a[i] ^ (1 << j)];
        }
	}
	printf("%lld\n", ans / 2);
	return 0;
}