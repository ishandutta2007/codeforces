#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set<ll> a;
    set<int> divs;
    for(int i = 1; i * ll(i) <= n; ++i) {
        if (n % i == 0) {
            divs.insert(i);
            divs.insert(n / i);
        }
    }
    for(auto x: divs) {
        ll z = (n - x) / x;
        a.insert((z * (z + 1)) / 2 * x + n / x);
    }
    for(auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}