#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll tm = 0;
        ll used = 1;
        ll sum = 1;
        for (; used <= k && sum < n; ) {
            ++tm;
            sum += used;
            used *= 2;
        }
        if (sum < n) {
            tm += (n - sum + k - 1) / k;
        }
        cout << tm << "\n";
    }
    
}