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
int arr[200000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> arr[i];
	}
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;
	int ans[2] = { 0 };
	for (llong t = 1ll << 31; t; t >>= 1) {
        int j = 0, k = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && arr[j] < arr[i] + t) ++j;
            while (k < n && arr[k] < arr[i] + t + t) ++k;
            if (j < n && arr[j] == arr[i] + t) {
                if (k < n && arr[k] == arr[j] + t) {
                    printf("3\n%d %d %d\n", arr[i], arr[j], arr[k]);
                    return 0;
                }
                ans[0] = arr[i];
                ans[1] = arr[j];
            }
        }
	}
	if (ans[0] != ans[1]) printf("2\n%d %d\n", ans[0], ans[1]);
	else printf("1\n%d\n", arr[0]);
	return 0;
}