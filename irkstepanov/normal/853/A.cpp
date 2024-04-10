#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> op(n + k + 100, -1);
    map<ll, vector<int> > mapa;
    for (int i = 0; i < k; ++i) {
        mapa[a[i]].pb(i);
    }

    for (int t = k; !mapa.empty(); ++t) {
        if (t < n) {
            mapa[a[t]].pb(t);
        }
        op[t] = (--mapa.end())->second.back();
        (--mapa.end())->second.pop_back();
        if ((--mapa.end())->second.empty()) {
            mapa.erase(--mapa.end());
        }
    }

    ll sum = 0;
    for (int t = k; op[t] != -1; ++t) {
        int id = op[t];
        sum += ll(t - id) * a[id];
    }

    cout << sum << "\n";
    vector<int> ans(n);
    for (int t = k; op[t] != -1; ++t) {
        ans[op[t]] = t;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

}