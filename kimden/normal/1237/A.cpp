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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += 55556;
    }
    int o = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
            ++o;
            if (o % 2 == 1) {
                ++a[i];
            }
        }
        cout << a[i] / 2 - 55556 / 2 << "\n";
    }


}