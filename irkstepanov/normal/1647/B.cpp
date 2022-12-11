#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool in(int x, pii p) {
    return (x >= p.first && x <= p.second);
}

bool bad(pii a, pii b) {
    if (a == b) {
        return false;
    }
    return (in(a.first, b) || in(a.second, b) || in(b.first, a) || in(b.second, a));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<pii> pr;
        bool valid = true;
        for (int j = 0; j < m; ++j) {
            vector<pii> nx;
            int l = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == '1') {
                    if (l == -1) {
                        l = i;
                    }
                } else {
                    if (l != -1) {
                        nx.pb({l, i - 1});
                        l = -1;
                    }
                }
            }
            if (l != -1) {
                nx.pb({l, n - 1});
            }
            for (pii x : pr) {
                for (pii y : nx) {
                    if (bad(x, y)) {
                        valid = false;
                    }
                }
            }
            pr = nx;
        }
        cout << (valid ? "YES" : "NO") << "\n";
    }

}