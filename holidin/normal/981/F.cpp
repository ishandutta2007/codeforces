#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 1;

vector <long long> a, b, v;

int main() {
    long long i, j, L, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> L;
    a.resize(n);
    for (i = 0; i < n; ++i)
        cin >> a[i];
    b.resize(n);
    for (j = 0; j < n; ++j)
        cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i = 0; i < a.size(); ++i)
        v.push_back(b[i] - L);
    for (i = 0; i < a.size(); ++i)
        v.push_back(b[i]);
    for (i = 0; i < a.size(); ++i)
        v.push_back(b[i] + L);
    long long l = 0, r = L/2 + 1;
    while (r - l > 1) {
        long long x = (l + r)/2 - 1;
        long long l1 = 0;
        while (a[0] - v[l1] > x) ++l1;
        long long r1 = 3*n - 1;
        while (v[r1] - a[0] > x) --r1;
        if (l1 > r1) {
            l = x + 1;
            continue;
        }
        long long mxl = l1 - n, mnr = r1 - n;
        bool flag = false;
        for (i = 1; i < n; ++i) {
            while (a[i] - v[l1] > x) ++l1;
            while (r1 < 3 * n - 1 && v[r1 + 1] - a[i] <= x) ++r1;
            mxl = max(mxl, l1 - n - i);
            mnr = min(mnr, r1 - n - i);
        }
        if (mxl <= mnr)
            r = x +  1;
        else
            l = x + 1;
    }
    cout << l;
}