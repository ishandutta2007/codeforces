// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll ask(ll x, ll y) {
    cout << "? " << x << ' ' << y << '\n' << flush;
    ll z;
    cin >> z;
    return z;
}

const ll W = 1'000'000'000;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    ll a = ask(1, 1);
    ll b = ask(W, 1);
    ll c = ask(W, W);

    ll xab = (a - b + W + 1) / 2;

    ll d = ask(xab, 1);
    ll o = ask(xab, W);

    ll x = 1 + a - d;
    ll y = 1 + d;

    ll p = o + W - c;
    ll q = W - o;

    cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << '\n' << flush;
}