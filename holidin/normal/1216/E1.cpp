#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5e5;
long long pr[N], dp[N];
set <pair<long long, int> > s;

long long cf(long long x) {
    return (x * (x + 1)) / 2;
}


long long f(long long x) {
    long long cnt = 1, ans = 0, t;
    for (t = 10; t <= x + 1; t *= 10) {
        ans += (cf(t - t / 10) + (x - t + 1) * (t - t / 10)) * cnt;
        ++cnt;
    }
    t /= 10;
    return ans + cf(x - t + 1) * cnt;
}

int coun(int x) {
    long long cnt = 1, ans = 0, t;
    for (t = 10; t <= x + 1; t *= 10) {
        ans += (t - t / 10) * cnt;
        ++cnt;
    }
    t /= 10;
    return ans + (x - t + 1) * cnt;
}

int f1(int x) {
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) / 2 - 1;
        if (coun(mid) < x)
            l = mid + 1;
        else
            r = mid + 1;
    }
    int y = x - coun(l - 1);
    vector <int> v;
    while (l > 0) {
        v.push_back(l % 10);
        l /= 10;
    }
    return v[v.size() - y];
}

signed main() {
    int i, j, k, n, x, q;
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> x;
        long long l = 1, r = 1e9;
        while (r - l > 1) {
            long long mid = (l + r) / 2 - 1;
            if (f(mid) < x)
                l = mid + 1;
            else
                r = mid + 1;
        }
        cout << f1(x - f(l - 1)) << "\n";
    }
}