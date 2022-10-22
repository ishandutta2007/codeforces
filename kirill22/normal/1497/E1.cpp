#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

vector<int> eratosfen(int n) {
    vector<int> d(n + 1, 1);
    vector<int> prime;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) {
            d[i] = i;
            prime.push_back(i);
        }
        for (auto x : prime) {
            if (x * i > n || x > d[i]) break;
            d[x * i] = x;
        }
    }
    return d;
}

vector<int> d;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map<int, int> b;
        while (a[i] > 1) {
            b[d[a[i]]]++;
            a[i] /= d[a[i]];
        }
        for (auto el : b) {
            if (el.se % 2 == 1) a[i] *= el.fi;
        }
    }
    int ans = 1;
    set<int> tmp;
    for (auto x : a) {
        if (tmp.find(x) != tmp.end()) {
            ans++;
            tmp = {x};
        }
        else {
            tmp.insert(x);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d = eratosfen(1e7 + 10);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}