#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1000005;
ll bit[1000005];
ll lowbit(ll x) { return x & -x; }
void add(ll k, ll x) {
    k += 2;
    while (k < maxn) {
        bit[k] += x;
        k += lowbit(k);
    }
}
ll query(ll k) {
    k += 2;
    ll ans = 0;
    while (k) {
        ans += bit[k];
        k -= lowbit(k);
    }
    return ans;
}
struct line {
    ll x, s, e;
} a[maxn], b[maxn];
bool cmp(line a, line b) { return a.s < b.s; }
bool cmp1(line a, line b) { return a.x < b.x; }
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans = 1;

    for (int i = 1; i <= n; i++) {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        a[i] = {aa, bb, cc};
        if (bb == 0 && cc == 1000000) ans++;
    }
    for (int i = 1; i <= m; i++) {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        b[i] = {aa, bb, cc};
        if (bb == 0 && cc == 1000000) ans++;
    }
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + m, cmp);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > >
        que;
    int p = 1;
    int p1 = 1;
    for (int i = 0; i <= 1000000; i++) {
        while (p <= m && b[p].s <= i) {
            add(b[p].x, 1);
            que.push(pair<ll, ll>(b[p].e, b[p].x));
            p++;
        }
        while (!que.empty() && que.top().first < i) {
            add(que.top().second, -1);
            que.pop();
        }
        while (p1 <= n && a[p1].x == i) {
            ans += (query(a[p1].e) - query(a[p1].s - 1));
            p1++;
        }
    }
    cout << ans << endl;
}