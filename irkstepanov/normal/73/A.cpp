#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

ll opt(vector<ll> v, ll sum) {
    if (sum < sz(v)) {
        return 0;
    }
    if (sz(v) == 1) {
        return min(v[0], sum);
    }
    ll x = 0;
    ll lst = v.back();
    v.pop_back();
    x = max(x, opt(v, sum - 1));
    x = max(x, opt(v, sum - lst) * lst);
    ll val = sum / (sz(v) + 1);
    if (1 <= val && val <= lst) {
        x = max(x, opt(v, sum - val) * val);
    }
    if (val + 1 <= lst) {
        x = max(x, opt(v, sum - val - 1) * (val + 1));
    }
    return x;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    ll sum;
    cin >> sum;
    sum += 3;

    ll ans = 0;
    for (int i = 0; i < 6; ++i) {
        ans = max(ans, opt(a, sum));
        next_permutation(all(a));
    }
    cout << ans << "\n";

}