#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1e9 + 7;

int gcd(int a, int b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    int k = 0;

    for (int i = 1; i < n; ++i) {
        vector<int> d;
        for (int j = 0; j < m; ++j) {
            d.pb(v[i][j] - v[0][j]);
        }
        sort(all(d));
        d.resize(unique(all(d)) - d.begin());
        for (int q = 0; q < sz(d); ++q) {
            for (int w = q + 1; w < sz(d); ++w) {
                k = gcd(k, abs(d[q] - d[w]));
            }
        }
    }

    if (k == 0) {
        k = inf;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] >= k) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n" << k << "\n";
    vector<int> a(n), b(m);
    a[0] = 0;

    for (int j = 0; j < m; ++j) {
        b[j] = v[0][j];
    }

    for (int i = 1; i < n; ++i) {
        a[i] = v[i][0] - b[0];
        if (a[i] < 0) {
            a[i] += k;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int j = 0; j < m; ++j) {
        cout << b[j] << " ";
    }
    cout << "\n";

}