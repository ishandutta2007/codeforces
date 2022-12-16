#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll par[1100000];
ll getPar(ll x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(ll x, ll y) {
    if (getPar(x) == getPar(y)) return;
    par[getPar(x)] = getPar(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll p, k;
    cin >> p >> k;

    for (ll i = 0; i < p; i++) par[i] = i;

    for (ll i = 1; i < p; i++) {
        if ((k*i)%p != 0) Union((k*i)%p, i);
    }

    unordered_set<int> seen;
    for (ll i = 1; i < p; i++) {
        seen.insert(getPar(i));
    }

    ll pw = seen.size();
    if (k == 1) pw = p;

    ll blah = 1;
    for (ll i = 0; i < pw; i++) {
        blah *= p;
        blah %=(ll) 1e9+7;
    }
    cout << blah << endl;
}