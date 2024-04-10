#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll cnt[N];
struct query {
    ll l, r, id;
};
query q[N];
ll ans[N];
ll bit[N];
vector<ll> v[N];

void add(ll pos, ll x) {
    while (pos < N) {
        bit[pos] += x;
        pos += pos & -pos;
    }
}

ll qry(ll pos) {
    ll res = 0;
    while (pos) {
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i = 1; i <= 400000; i++) {
        for (ll j = i + i; j <= 400000; j += i) {
            v[j].push_back(i);
        }
    }
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + t, [](query a, query b) {
        return a.r < b.r;
    });
    ll pos = 1;
    for (ll i = 1; i <= t; i++) {
        while (pos <= q[i].r) {
            for (auto fac: v[pos * 2]) {
                if (pos % 3 == 0 && pos / 3 < fac && fac < 2 * pos / 3) add(fac, 1);
            }
            pos++;
        }
        ans[q[i].id] = qry(N - 1) - qry(q[i].l - 1);
    }
    sort(q + 1, q + 1 + t, [](query a, query b) { return a.l > b.l; });
    memset(bit, 0, sizeof bit);
    pos = 200000;
    for (ll i = 1; i <= t; i++) {
        while (q[i].l <= pos) {
            for (ll j = pos + pos; j <= 200000; j += pos) {
                add(j, cnt[j]);
                cnt[j]++;
            }
            pos--;
        }
        ans[q[i].id] += qry(q[i].r) - qry(q[i].l - 1);
    }

    for (ll i = 1; i <= t; i++) {
        ll len = q[i].r - q[i].l + 1;
        ans[q[i].id] = len * (len - 1) * (len - 2) / 6 - ans[q[i].id];
    }
    for (ll i = 1; i <= t; i++) cout << ans[i] << endl;
//    ll t;
//    cin >> t;
//    while (t--) {
//        ll l, r;
//        cin >> l >> r;
//        memset(cnt, 0, sizeof cnt);
//        for (ll i = l; i <= r; i++) {
//            for (ll j = i + i; j <= r; j += i) {
//                cnt[j]++;
//            }
//        }
//        ll ans = 0;
//        for (ll i = l; i <= r; i++) {
//            for (ll j = i; j <= 2 * r; j += i) {
//                if (j % 2 != 0) continue;
//                ll act = j / 2;
//                if (act % 3 == 0 && act / 3 < i && i < 2 * act / 3) ans++;
//            }
//        }
//        for (ll i = l; i <= r; i++) {
////            ans += cnt[i] * (cnt[i] - 1) / 2;
//        }
//        ll len = r - l + 1;
//        ans = len * (len - 1) * (len - 2) / 6 - ans;
//        cout << ans << endl;
//
//    }
}

//3
//1
//78991
//969
//109229059733605

//4
//1
//79063
//969
//109229066941243