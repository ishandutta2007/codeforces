#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    int aa = 0, bb = 0;
    while (bb < n) {
        if (a[aa] == b[bb]) {
            ++aa;
            ++bb;
        } else if (c[a[aa]]) {
            ++aa;
        } else {
            ++ans;
            c[b[bb]] = 1;
            ++bb;
        }
    }
    cout << ans << "\n";


}