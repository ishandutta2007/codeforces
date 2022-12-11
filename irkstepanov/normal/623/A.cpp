#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("division.in");
    //ofstream cout("division.out");

    int n;
    cin >> n;

    vector<vector<char> > g(n, vector<char>(n, false));
    int m;
    cin >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u][v] = g[v][u] = true;
    }

    vector<char> s(n);
    set<vector<int> > bad;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) {
                ++cnt;
            } else if (i != j) {
                v.pb(j);
            }
        }
        if (cnt == n - 1) {
            s[i] = 'b';
        } else {
            bad.insert(v);
        }
    }

    if (sz(bad) > 2) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    if (sz(bad) >= 2) {
        vector<int> a = *bad.begin();
        auto it = bad.begin();
        ++it;
        vector<int> c = *it;
        for (int i : a) {
            s[i] = 'a';
        }
        for (int i : c) {
            s[i] = 'c';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i];
    }
    cout << "\n";

}