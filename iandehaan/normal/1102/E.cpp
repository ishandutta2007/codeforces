#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll a[n];
    map<ll, int> lastocc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lastocc[a[i]] = i;
    }

    int baduntil = 0;
    ll out = 1;
    for (int i = 0; i < n; i++) {
        if (i > baduntil) {
            out *= 2;
            out %= mod;
        }
        baduntil = max(baduntil, lastocc[a[i]]);
    }
    cout << out << endl;
}