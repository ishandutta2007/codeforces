#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 2e5 + 5;

ll q, n, k, a[N];

int main() {
    cin >> q;
    while (q--) {
        cin >> n >> k;

        ll odd = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            odd += a[i] & 1;
        }

        if (odd >= k && (odd & 1) == (k & 1)) {
            cout << "YES" << endl;
            ll cnt = 0, sum = 0, rem = k;
            for (int i = 0; i < n; ++i) {
                cnt++;
                sum += a[i];
                if (rem > 1 && (sum & 1)) {
                    cout << i + 1 << " ";
                    cnt = sum = 0;
                    --rem;
                }
            }
            cout << n << endl;
        }
        else
            cout << "NO" << endl;
    }
}