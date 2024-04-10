#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
vector<ll> a, b, c;
vector<ll> p;
vector<vector<ll>> ne;
vector<ll> countOne;
vector<ll> countZero;
vector<bool> flipOne;
vector<bool> flipZero;

void fillP(ll n) {
    vector<bool> v(n, false);
    v[0] = true;
    queue<tuple<ll, ll>> toVisit;
    toVisit.push(make_tuple(0, 0));
    while (!toVisit.empty()) {
        auto s = toVisit.front();
        toVisit.pop();
        ll x = get<0>(s), y = get<1>(s);
        v[x] = true;
        p[x] = y;
        for (auto t : ne[x]) {
            if (!v[t]) toVisit.push(make_tuple(t, x));
        }
    }
}

void remakeA(void) {
    queue<ll> toVisit;
    toVisit.push(0);
    while (!toVisit.empty()) {
        ll s = toVisit.front();
        toVisit.pop();
        if (a[s] > a[p[s]]) a[s] = a[p[s]];
        for (auto v : ne[s]) {
            if (v != p[s]) toVisit.push(v);
        }
    }
}

ll shuffle(ll v) {
    ll count = 0;
    for (auto x : ne[v]) {
        if (x != p[v]) count += shuffle(x);
    }
    ll tempCountOne = 0;
    ll tempCountZero = 0;
    for (auto x : ne[v]) {
        if (x != p[v]) {
            tempCountOne += countOne[x];
            tempCountZero += countZero[x];
        }
    }
    if (flipOne[v]) tempCountOne++;
    if (flipZero[v]) tempCountZero++;
    ll minCount = min(tempCountOne, tempCountZero);
    count += 2 * minCount * a[v];
    countOne[v] = tempCountOne - minCount;
    countZero[v] = tempCountZero - minCount;
    return count;
}

int main(void) {
    ll n;
    cin >> n;
    ll zero = 0, one = 0;
    flipOne = vector<bool>(n, false);
    flipZero = vector<bool>(n, false);
    p = vector<ll>(n);
    countOne = vector<ll>(n);
    countZero = vector<ll>(n);
    for (ll i = 0; i < n; i++) {
        ll aa, bb, cc;
        cin >> aa >> bb >> cc;
        a.push_back(aa), b.push_back(bb), c.push_back(cc);
        if (bb == 0 && cc == 1) { one++; flipOne[i] = true; }
        if (bb == 1 && cc == 0) { zero++; flipZero[i] = true; }
    }

    ne = vector<vector<ll>>(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        ne[u - 1].push_back(v - 1);
        ne[v - 1].push_back(u - 1);
    }
    if (one != zero) cout << "-1\n";
    else {
        fillP(n);
        remakeA();
        cout << shuffle(0) << "\n";
    }
}