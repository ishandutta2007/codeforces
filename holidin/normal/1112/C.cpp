#include <bits/stdc++.h>
#define fi first
#define se second
#define sqr(a) ((a) * (a))
#define ll long long
#define ld lond double
using namespace std;
const long long N = 6e5 + 1;
const long long inf = 1e9 + 1;

long long nx[N], a[N], cnt[N], ct[N], ls[N], n, k, m;

void solve(long long l, long long r) {
    vector <long long> er;
    for (long long i = 0; i < (l - 1) % k; ++i)
        er.push_back(i + 1);
    for (long long i = 1; i < N; ++i)
        ct[i] = 0;
    long long ff = 0;
    for (long long i = l; i <= r; ++i)
    if (r - l + 1 - ff > k)
        if (ct[a[i]] >= cnt[a[i]])
            er.push_back(i), ++ff;
        else
            ++ct[a[i]];
    cout << er.size() << endl;
    for (long long i = 0; i < er.size(); ++i)
        cout << er[i] << ' ';
    exit(0);
}

int main() {
    long long i, j, r, s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> k >> n >> s;
    for (i = 1; i <= m; ++i) {
        cin >> a[i];
        if (ls[a[i]] != 0)
            nx[ls[a[i]]] = i;
        ls[a[i]] = i;
    }
    for (i = 1; i <= s; ++i) {
        cin >> j;
        ++cnt[j];
    }
    r = 0;
    bool flag = 0;
    for (i = 1; i < N; ++i) {
        while (r < m && cnt[i] > ct[i]) {
            ++r;
            ++ct[a[r]];
            ls[a[r]] = r;
        }
        if (cnt[i] > ct[i])
            flag = 1;
    }
    if (flag) {
        cout << -1;
        return 0;
    }
    while (r < k) {
            ++r;
            ++ct[a[r]];
            ls[a[r]] = r;
        }
    if (r + (n - 1) * k <= m)
        solve(1, r);
    for (i = 1; i < m - k; ++i) {
        --ct[a[i]];
        if (ct[a[i]] < cnt[a[i]]) {
            while (r < m && ct[a[i]] < cnt[a[i]]) {
                ++r;
                ++ct[a[r]];
                ls[a[r]] = r;
            }
            if (ct[a[i]] < cnt[a[i]]) {
                cout << -1;
                return 0;
            }
        }
        while (r < i + k) {
            ++r;
            ++ct[a[r]];
            ls[a[r]] = r;
        }
        long long cnt = (i / k) + (m - r) / k;
        if (cnt >= n - 1) {
            solve(i + 1, r);
        }
    }
    cout << -1;
}