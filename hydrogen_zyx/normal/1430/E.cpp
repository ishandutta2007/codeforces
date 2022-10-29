#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[300000];
char b[300000];
vector<ll> bit[30];
vector<ll> pos[30];
ll p[30];

void padd(ll num, ll k, ll x) {
    while (k < bit[num].size()) {
        bit[num][k] += x;
        k += k & -k;
    }
}
void add(ll num, ll l, ll r, ll x) {
    padd(num, l, x);
    padd(num, r + 1, -x);
}

ll query(ll num, ll k) {
    ll ans = 0;
    while (k) {
        ans += bit[num][k];
        k -= k & -k;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < 26; i++) {
        bit[i].push_back(0);
        pos[i].push_back(0);
        p[i] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[n - i + 1] = a[i];
        pos[a[i] - 'a'].push_back(i);
    }
    for (ll i = 0; i < 26; i++) bit[i].resize(pos[i].size() + 5);
    for (ll i = 0; i < 26; i++) {
        for (ll j = 1; j < pos[i].size(); j++) {
            add(i, j, j, pos[i][j]);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll wei = query(b[i] - 'a', p[b[i] - 'a']);
        ll po = pos[b[i] - 'a'][p[b[i] - 'a']++];
        ans += wei - i;
        for (ll j = 0; j < 26; j++) {
            ll p = upper_bound(pos[j].begin(), pos[j].end(), po) -
                   pos[j].begin() - 1;
            add(j, 1, p, 1);
        }
    }
    cout << ans;
}