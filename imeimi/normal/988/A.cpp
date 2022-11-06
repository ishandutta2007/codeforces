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

int n, k;
int idx[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	int t;
	for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (idx[t] == 0) {
            if (--k == 0) {
                printf("YES\n");
                for (int j = 1; j <= 100; ++j) {
                    if (idx[j]) printf("%d ", idx[j]);
                }
                printf("%d\n", i);
                return 0;
            }
        }
        idx[t] = i;
	}
	printf("NO\n");
	return 0;
}