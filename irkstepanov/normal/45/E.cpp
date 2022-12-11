#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int get(vector<string> a, vector<string> b) {
    map<char, int> m1, m2;
    for (int i = 0; i < sz(a); ++i) {
        ++m1[a[i][0]];
    }
    for (int i = 0; i < sz(b); ++i) {
        ++m2[b[i][0]];
    }
    int ans = 0;
    for (auto it : m1) {
        ans += min(it.second, m2[it.first]);
    }
    return ans;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }

    sort(all(a));
    sort(all(b));

    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][0] == b[j][0]) {
                g[i].pb(j);
            }
        }
    }

    int mm = get(a, b);

    vector<bool> al1(n, true), al2(n, true);
    for (int iter = 0; iter < n; ++iter) {
        int opt = -1;
        for (int j = 0; j < n; ++j) {
            if (!al2[j]) {
                continue;
            }
            vector<string> u, v;
            for (int i = iter + 1; i < n; ++i) {
                u.pb(a[i]);
            }
            for (int i = 0; i < n; ++i) {
                if (!al2[i] || i == j) {
                    continue;
                }
                v.pb(b[i]);
            }
            int cnt = get(u, v);
            if (a[iter][0] == b[j][0]) {
                ++cnt;
            }
            if (cnt == mm) {
                opt = j;
                break;
            }
        }
        if (a[iter][0] == b[opt][0]) {
            --mm;
        }
        al1[iter] = al2[opt] = false;
        cout << a[iter] << " " << b[opt];
        if (iter != n - 1) {
            cout << ", ";
        }
    }
    cout << "\n";

}