#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

unordered_map<ll, ll> seen;

ll nxt(ll curr) {
    if (seen.find(curr) == seen.end()) return curr;
    return seen[curr] = nxt(seen[curr]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for (ll i = 0; i < n; i++) cin >> a[i].second;
    for (ll i = 0; i < n; i++) cin >> a[i].first;
    sort(a, a+n);
    ll out = 0;
    for (ll i = n-1; i >= 0; i--) {
            out += a[i].first*(nxt(a[i].second)-a[i].second);
            seen[nxt(a[i].second)] = nxt(a[i].second)+1;
    }
    cout << out << endl;
}