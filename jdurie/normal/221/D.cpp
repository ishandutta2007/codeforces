#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define A(a) (a).begin(), (a).end()
#define N 100010
#define S 315

ll a[N], ct[N], l[N], r[N], ans[N], curAns = 0;

void update(ll i, ll d) {
    if(a[i] >= N) return;
    if(ct[a[i]] == a[i]) curAns--;
    ct[a[i]] += d;
    if(ct[a[i]] == a[i]) curAns++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 1, n + 1) cin >> a[i];
    vector<ll> q;
    F(i, 0, m) cin >> l[i] >> r[i], q.push_back(i);
    sort(A(q), [](ll i, ll j) {
        if(l[i] / S - l[j] / S) return l[i] / S < l[j] / S;
        return l[i] / S % 2 ? r[i] > r[j] : r[i] < r[j];
    });
    ll cL = 1, cR = 0;
    for(ll i : q) {
        while(cL < l[i]) update(cL++, -1);
        while(cL > l[i]) update(--cL, 1);
        while(cR < r[i]) update(++cR, 1);
        while(cR > r[i]) update(cR--, -1);
        ans[i] = curAns;
    }
    F(i, 0, m) cout << ans[i] << '\n';
}