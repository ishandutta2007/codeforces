#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int k = 1; ; ++k) {
        int val = k * (k + 1) / 2;
        if (val == n) {
            cout << "YES\n";
            return 0;
        }
        if (val > n) {
            cout << "NO\n";
            return 0;
        }
    }
 
}