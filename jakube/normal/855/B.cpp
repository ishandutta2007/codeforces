#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> maxl(n), minl(n);
    maxl[0] = a[0];
    minl[0] = a[0];
    for (int i = 1; i < n; i++) {
        maxl[i] = max(maxl[i-1], a[i]);
        minl[i] = min(minl[i-1], a[i]);
    }
    vector<int> maxr(n), minr(n);
    maxr[n-1] = a[n-1];
    minr[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        maxr[i] = max(maxr[i+1], a[i]);
        minr[i] = min(minr[i+1], a[i]);
    }

    long long result = numeric_limits<long long>::min();
    for (int i = 0; i < n; i++) {
        long long cur = q*a[i];
        if (p > 0)
            cur += maxl[i] * p;
        else
            cur += minl[i] * p;
        if (r > 0)
            cur += maxr[i] * r;
        else
            cur += minr[i] * r;

        result = max(result, cur);
    }

    cout << result << endl;
}