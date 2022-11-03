#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;

const ll MAXN = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    ll a, sum = 0, mx = -98791;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }
    sum = mx * n - sum;
    cout << sum << endl;

    return 0;
}