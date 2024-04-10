#include <bits/stdc++.h>
using namespace std;
const long long inf5 = 1e18;
multiset <long long> s[5];
vector <long long> v;
long long nf[5];

int main() {
    int i, j;
    long long n, k, b, l, c, cc, t;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> b >> cc;
    b = min(b, 5 * cc);
    for (i = 0; i < n; ++i) {
        cin >> t;
        t += 1e9;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    long long ans = 8e18;
    for (i = 0; i < v.size(); ++i) {
        for (j = 0; j <= 4; ++j) {
            long long c = v[i] + ((j - v[i]) % 5 + 5) % 5;
            long long st = (c / 5) * b;
            if (v[i] % 5 <= j)
                st -= (j - v[i] % 5) * cc;
            else
                st -= (5 - v[i] % 5 + j) * cc;
            if (s[j].size() < k) {
                s[j].insert(st);
                nf[j] += st;
            } else if (*s[j].begin() < st) {
                    nf[j] += st - *s[j].begin();
                    s[j].erase(s[j].begin());
                    s[j].insert(st);
                }
        }
        if (i >= k - 1) {
            for (l = v[i]; l < v[i] + 5; ++l)
                ans = min(ans, ((l / 5) * b * k) - nf[l % 5]);
        }
    }
    cout << ans;
}