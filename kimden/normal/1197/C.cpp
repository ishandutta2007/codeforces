#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> diff;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            diff.push_back(a[i] - a[i - 1]);
        }
    }
    ll cost = a[n - 1] - a[0];
    sort(rall(diff));
    for (int i = 0; i < k - 1; ++i) {
        cost -= diff[i];
    }
    cout << cost << "\n";
}