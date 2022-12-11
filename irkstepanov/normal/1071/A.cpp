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

    ll a, b;
    cin >> a >> b;

    ll k = 0;
    ll sum = 0;
    while (sum + (k + 1) <= a + b) {
        ++k;
        sum += k;
    }

    vector<bool> used(k + 1, false);
    vector<ll> lf;
    int ptr = k;
    bool swapped = false;
    if (a > b) {
        swap(a, b);
        swapped = true;
    }


    while (a) {
        if (ptr <= a) {
            lf.pb(ptr);
            used[ptr] = true;
            a -= ptr;
            --ptr;
            continue;
        }
        lf.pb(a);
        used[a] = true;
        break;
    }

    vector<ll> rg;
    for (int i = 1; i <= k; ++i) {
        if (!used[i]) {
            rg.pb(i);
        }
    }

    if (swapped) {
        swap(lf, rg);
    }

    sort(all(lf));
    sort(all(rg));

    cout << sz(lf) << "\n";
    for (ll x : lf) {
        cout << x << " ";
    }
    cout << "\n";

    cout << sz(rg) << "\n";
    for (ll x : rg) {
        cout << x << " ";
    }
    cout << "\n";
 
}