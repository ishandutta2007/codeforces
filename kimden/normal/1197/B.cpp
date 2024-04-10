#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int idx = 0;
    vector<int> vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > a[idx]) {
            idx = i;
        }
        vals.push_back(a[i]);
    }
    sort(rall(vals));
    int ptr = 1;
    int l = idx - 1, r = idx + 1;
    while (ptr < n) {
        if (l >= 0 && a[l] == vals[ptr]) {
            --l, ++ptr;
        } else if (r < n && a[r] == vals[ptr]) {
            ++r, ++ptr;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}