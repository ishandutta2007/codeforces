#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct random_variable {
    map<ll, ld> xi;
};

map<ll, ll> a, sum;

random_variable solve(ll v) {
    if (!sum.count(v * 2) && !sum.count(v * 2 + 1)) {
        map<ll, ld> ans;
        ans[a[v]] = 1.0;
        return {ans};
    }
    ll lf = 0, rg = 0;
    if (sum.count(v * 2)) {
        lf = sum[v * 2];
    }
    if (sum.count(v * 2 + 1)) {
        rg = sum[v * 2 + 1];
    }
    ll son1 = v * 2, son2 = v * 2 + 1;
    if (lf < rg) {
        swap(lf, rg);
        swap(son1, son2);
    }
    if (a.count(v)) {
        lf += a[v];
    }
    random_variable eta = solve(son1);
    if (a.count(v)) {
        rg += a[v];
    }
    while (true) {
        map<ll, ld>::iterator it = eta.xi.begin();
        if (it->first < rg) {
            eta.xi[rg] += it->second;
            eta.xi.erase(eta.xi.begin());
        } else {
            break;
        }
    }
    for (map<ll, ld>::iterator it = eta.xi.begin(); it != eta.xi.end(); ++it) {
        it->second /= 2;
    }
    eta.xi[lf] += 0.5;
    return eta;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, q;
    cin >> n >> q;


    a[1] = sum[1] = 0;

    cout << fixed;
    cout.precision(10);

    while (q--) {
        string s;
        cin >> s;
        if (s == "add") {
            ll v;
            cin >> v;
            ll val;
            cin >> val;
            a[v] += val;
            sum[v] += val;
            ll curr = v / 2;
            while (curr > 0) {
                sum[curr] += val;
                curr /= 2;
            }
            continue;
        }

        random_variable eta = solve(1);
        ld ans = 0;
        for (auto it : eta.xi) {
            ans += it.first * it.second;
        }
        cout << ans << "\n";
    }

}