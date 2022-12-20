#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> a;
    vector<ll> c;
    ll ai, ci;
    cin >> ai >> ci;
    while (ai) {
        a.pb(ai%3);
        //cout << ai%3 << ' ';
        ai /= 3;
    }
    //cout << endl;
    while (ci) {
        c.pb(ci%3);
        //cout << ci%3 << ' ';
        ci /= 3;
    }
    //cout << endl;

    while (a.size() > c.size()) {
        c.pb(0);
    }
    while (c.size() > a.size()) {
        a.pb(0);
    }

    vector<ll> b;

    for (ll i = 0; i < a.size(); i++) {
        for (ll j = 0; j < 3; j++) {
            if ((a[i] + j)%3 == c[i]) {
                b.pb(j);
                break;
            }
        }
    }

    reverse(begin(b), end(b));

    ll out = 0;

    for (ll i = 0; i < b.size(); i++) {
        out *= 3;
        out += b[i];
    }
    cout << out << endl;
}