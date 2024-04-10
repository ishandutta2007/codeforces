#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 != m % 2) {
        cout << "0\n";
        return 0;
    }
    bool swapped = false;
    if (n < m) {
        swap(n, m);
        swapped = true;
    }
    assert(k < n);

    map<int, pii> mapa;
    for (int i = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        if (swapped) {
            swap(x, y);
        }
        --x, --y;
        if (mapa.count(x)) {
            pii p = mapa[x];
            ++p.first;
            p.second *= c;
            mapa[x] = p;
        } else {
            mapa[x] = {1, c};
        }
    }

    bool ok = true;
    for (auto it : mapa) {
        if (it.second.first == m && it.second.second == 1) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "0\n";
        return 0;
    }

    int fr;
    for (int i = 0; i < n; ++i) {
        if (!mapa.count(i)) {
            fr = i;
        }
    }

    int p;
    cin >> p;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (i == fr) {
            continue;
        }
        if (!mapa.count(i)) {
            for (int j = 0; j < m - 1; ++j) {
                ans += ans;
                if (ans >= p) {
                    ans -= p;
                }
            }
        } else {
            int f = mapa[i].first;
            for (int j = 0; j < m - f - 1; ++j) {
                ans += ans;
                if (ans >= p) {
                    ans -= p;
                }
            }
        }
    }

    cout << ans << "\n";

}