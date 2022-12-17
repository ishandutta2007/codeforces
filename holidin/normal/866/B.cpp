#include <bits/stdc++.h>
using namespace std;
const int N = 200000;

vector <pair<long long, int> > v;
long long a[N], k[N], b[N], d[N], sum, piz, l, r, i, n, s;

long long check(long long x) {
    for (i = 0; i < n; ++i)
        k[i] = d[i];
    long long ost = x * s;
    long long pred = piz * s - sum;
    //cout << pred << endl;
    long long sum = 0;
    for (i = 0; i < n; ++i)
    if (v[i].first >= 0) {
        long long t = min(ost, k[v[i].second]);
        k[v[i].second] -= t;
        sum += a[v[i].second] * t;
        ost -= t;
    } else {
        if (ost <= pred)
            continue;
        long long t = max(min(ost - pred, k[v[i].second]), (long long) 0);
        k[v[i].second] -= t;
        sum += a[v[i].second] * t;
        ost -= t;
    }
    for (i = 0; i < n; ++i) {
         sum += k[i] * b[i];
    }
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> s;
    for (i = 0; i < n; ++i) {
        cin >> d[i] >> a[i] >> b[i];
        v.push_back(make_pair(b[i] - a[i], i));
        sum += d[i];
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; ++i) {
        v[i].first = -v[i].first;
    }
    piz = sum / s;
    if (piz * s < sum)
         ++piz;
    l = 0;
    r = piz + 1;
    while (r - l > 1) {
        long long x = (l + r)/2;
        if (check(x) >= (check(x - 1)))
            l = x;
        else
            r = x;
    }
    cout << check(l);
}