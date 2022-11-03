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

typedef long long ll;

using namespace std;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = n;
    unordered_set<int> q;
    for (int l = 0; l <= n; l++) {
        q.clear();
        bool ok = true;
        for (int j = 0; j < l; j++) {
            if (q.find(a[j]) == q.end()) {
                q.insert(a[j]);
            } else {
                ok = false;
                break;
            }
        }

        if (!ok) break;

        ans = min(ans, n - l);

        for (int r = n - 1; r >= l; r--) {
            if (q.find(a[r]) != q.end()) break;
            q.insert(a[r]);
            ans = min(ans, r - l);
        }
    }
    cout << ans << '\n';


    return 0;
}