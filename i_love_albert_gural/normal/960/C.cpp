#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll X, D;
    cin >> X >> D;

    ll val = 1;
    vll res;

    for (int pow = 0; X; pow++) {
        if (X&1) {
            if (pow) {
                for (int i = 0; i < pow; i++) {
                    res.push_back(val);
                }
                val += D;
            }

            res.push_back(val);
            val += D;
        }
        X /= 2;
    }

    cout << res.size() << "\n";
    for (ll v : res) cout << v << " ";
    cout << endl;

    return 0;
}