#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


inline bool square(int x) {
    int o = (int)sqrt(x);
    return (o * (ll)o == x);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "NO\n";
        } else if (n % 2 == 0 && square(n / 2)) {
            cout << "YES\n";
        } else if (n % 4 == 0 && square(n / 4)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }



}