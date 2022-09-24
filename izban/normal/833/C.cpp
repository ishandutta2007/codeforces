#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    ll l, r;
    while (cin >> l >> r) {
        ll L = l, R = r;
        vector<int> a, b;
        int n = 0;
        while (r > 0) {
            a.push_back(l % 10);
            b.push_back(r % 10);
            l /= 10;
            r /= 10;
            n++;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        vector<int> need(10);
        int l = 0;
        while (l < n && a[l] == b[l]) {
            need[a[l++]]++;
        }

        int ans = 0;
        vector<int> cnt(10);
        function<void(int, int)> rec = [&](int x, int left) {
            if (x == 10) {
                cnt[0] = left;

                auto c = cnt;
                int pref = 0;
                ll x = 0;
                while (pref <= n) {
                    if (pref == n) {
                        ans++;
                        return;
                    }
                    for (int i = b[pref] - 1; i >= 0; i--) {
                        if (c[i] > 0) {
                            c[i]--;
                            ll y = x * 10 + i;
                            for (int j = 9; j >= 0; j--) for (int k = 0; k < c[j]; k++) y = 10 * y + j;
                            if (y >= L) {
                                ans++;
                                return;
                            }
                            c[i]++;
                            break;
                        }
                    }

                    if (c[b[pref]] == 0) return;
                    c[b[pref]]--;
                    x = 10 * x + b[pref];
                    pref++;
                }
                ans++;
                return;
            }
            for (int i = need[x]; i <= left; i++) {
                cnt[x] = i;
                rec(x + 1, left - i);
            }
        };
        rec(1, n);
        cout << ans << endl;
    }

    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}