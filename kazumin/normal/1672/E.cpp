#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

map<int, int> mp;

int ask(int x) {
    if (mp.count(x)) return mp[x];
    cout << "? " << x << endl;
    int ret;
    cin >> ret;
    return mp[x] = ret;
}

int32_t main() {
    boost();

    int n;
    cin >> n;
    int lo = 1, hi = 5e6, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(mid) == 1) hi = mid;
        else lo = mid + 1;
    }
    int l = lo - n + 1, r = lo; //best area in [l, r]
    for (int i = l; i <= r; i++) {
        int b = i - l;
        for (int j = n; j >= n - b; j--) {
            if (i % j == 0) {
                int c = ask(i / j) * (i / j);
                if (c == i) {
                    cout << "! " << c << endl;
                    return 0;
                }
            }
        }
    }
    abort();

    return 0;
}