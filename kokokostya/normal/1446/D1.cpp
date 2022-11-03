#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

int n;

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    vector<int> a(n);
    for (int i  = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;

    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    int val = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int second_max = 0;
    for (int i = 0; i < n; i++) {
        if (i != val) {
            second_max = max(second_max, cnt[i]);
        }
    }

    if (second_max == cnt[val]) {
        cout << a.size() << '\n';
        return 0;
    }

    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i]].push_back(i);
    }
    vector<int> pref(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] += pref[i] + (a[i] == val);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] += suf[i + 1] + (a[i] == val);
    }
    vector<int> prev_val(n, -1), nxt_val(n, n);
    for (int i = 0; i < n; i++) {
        if (i) prev_val[i] = prev_val[i - 1];
        if (a[i] == val) prev_val[i] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 != n) nxt_val[i] = nxt_val[i + 1];
        if (a[i] == val) nxt_val[i] = i;
    }

    for (int i = 0; i < n; i++) {
        if (i == val) continue;
        if (cnt[i] == 0) continue;
        int need = cnt[val] - cnt[i];

        unordered_map<int, int> left;
        int cnt_i = 0;
        for (int j = 0; j < n; j++) {
            int val = pref[j] - cnt_i;
            if (left.find(val) == left.end()) {
                left[val] = j;
            }
            if (a[j] == i) cnt_i++;
        }


        cnt_i = 0;
        for (int j = n - 1; j >= 0; j--) {
            int val = suf[j + 1] - cnt_i;
            if (left.find(need - val) != left.end()) {
                ans = max(ans, j - left[need - val] + 1);
            }
            if (a[j] == i) cnt_i++;
        }

    }




    cout << ans << '\n';




    return 0;
}