#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 22;

int a[N];

void solve() {
    int i, j, k, n;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int t = 1, ans = 0;
    for (int h = 0; h < 27; ++h) {
        vector <int> v;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            v.push_back(a[i] % (2 * t));
        }
        sort(v.begin(), v.end());
        int lpos = v.size();
        int rpos = v.size() - 1;
        int lpos1 = 0;
        for (i = 0; i < v.size() && v[i] < t; ++i) {
            while (lpos > 0 && v[lpos - 1] + v[i] >= t && lpos - 1 > i)
                --lpos;
            while (lpos <= i)
                ++lpos;
            while (rpos >= 0 && v[rpos] + v[i] >= 2*t)
                --rpos;
            if (rpos >= lpos)
            cnt += (rpos - lpos + 1);
        }
        lpos = i;
        int cnt2 = 0;
        for (j = v.size() - 1; j >= i; --j) {
            while (lpos < v.size() && v[lpos] + v[j] < 3 * t) {
                ++lpos;
            }
            cnt2 += v.size() - lpos;
            if (v[j] + v[j] >= 3 * t)
                --cnt2;
        }
        cnt += cnt2 / 2;
        ans += (cnt % 2) * t;
        t *= 2;
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}