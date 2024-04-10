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

const llong mx = 1e18;
llong a, b;
int l[18], r[18];
void toc(int a[], llong x) {
    for (int i = 0; i < 18; ++i) {
        a[i] = x % 10;
        x /= 10;
    }
}

int tmp[10];
int cnt[10];
int tps[10];

int getAns() {
    if (b == mx && cnt[0] == 17 && cnt[1] == 1) return 1;
    for (int i = 18; i--; ) {
        if (l[i] == r[i]) {
            if (cnt[l[i]]-- == 0) return 0;
        }
        else {
            int j, k;
            if (l[i] + 1 < r[i]) {
                for (j = l[i] + 1; j < r[i]; ++j) {
                    if (cnt[j]) return 1;
                }
            }
            
            for (j = 0; j < 10; ++j) tps[j] = cnt[j];
            if (tps[l[i]]--) {
                for (j = i, k = 9; j--; ) {
                    while (k && tps[k] == 0) --k;
                    if (l[j] < k) return 1;
                    if (k < l[j]) break;
                    --tps[k];
                }
                if (j < 0) return 1;
            }
            
            for (j = 0; j < 10; ++j) tps[j] = cnt[j];
            if (tps[r[i]]--) {
                for (j = i, k = 0; j--; ) {
                    while (k < 9 && tps[k] == 0) ++k;
                    if (k < r[j]) return 1;
                    if (r[j] < k) break;
                    --tps[k];
                }
                if (j < 0) return 1;
            }
            return 0;
        }
    }
    return 1;
}

int pro(int i, int rem) {
    if (i == 0) {
        cnt[0] = rem;
        for (int i = 1; i < 10; ++i) cnt[i] = tmp[i];
        return getAns();
    }
    int ret = 0;
    for (int j = 0; j <= rem; ++j) {
        tmp[i] = j;
        ret += pro(i - 1, rem - j);
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	if (a == b) {
        printf("1\n");
        return 0;
	}
	toc(l, a);
	toc(r, min(b, mx - 1));
	printf("%d\n", pro(9, 18));
	return 0;
}