#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

ll f(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        ll h1, d1, h2, d2;
        cin >> h1 >> d1 >> h2 >> d2;
        ll k, w, a;
        cin >> k >> w >> a;
        bool ans = false;
        for (int i = 0; i <= k; ++i) {
            ll x = f(h2, d1 + w * i);
            ll y = f(h1 + a * (k - i), d2);
            if (x <= y) {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }

}