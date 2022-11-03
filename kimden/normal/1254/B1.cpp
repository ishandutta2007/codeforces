#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n;
vector<int> a, b;
ll sum;
ll ans;
const ll INF = 2e18;

ll calc(ll sz, ll bestans) {
    if (sz == 1) {
        return INF;
    }
    b = a;
    ll all_dist = 0;
    ll cur = 0;
    ll dist = 0;
    int cen = -1;
    for (int i = 0; i < n && all_dist < bestans; ++i) {
        if (cen < 0 && b[i] > sz) {
            b[i] %= sz;
        }
        if (cen < 0 && 2LL * (cur + b[i]) >= sz) {
            cen = i;
            all_dist += dist + cur;
        }
        ll here = min<ll>(b[i], sz - cur);
        if (cen >= 0) {
            all_dist += here * ll(i - cen);
        } else {
            dist += cur;
        }
        cur += here;
        if (cur == sz) {
            cur = 0;
            dist = 0;
            cen = -1;
            b[i] -= here;
            --i;
        }
    }
//    cerr << "calc(" << sz << ") = " << all_dist << endl;
    return all_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
//    n = 1000000;
    a.resize(n);
    sum = 0;
    ans = INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
//a[i] = (i == 0 ? 999997 : 1000000);
        sum += a[i];
    }
    for (int i = 2; i * (ll)i <= sum; ++i) {
        if (sum % i == 0) {
            while (sum % i == 0) {
                sum /= i;
            }
            ans = min(ans, calc(i, ans));
        }
    }
    if (sum > 1) {
        ans = min(ans, calc(sum, ans));
    }
    cout << (ans == INF ? -1 : ans) << "\n";

}