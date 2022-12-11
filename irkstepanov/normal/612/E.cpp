#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    scanf("%d", &n);

    vector<int> p(n);
    forn(i, n) {
        scanf("%d", &p[i]);
        --p[i];
    }

    vector<char> used(n, false);
    vector<vector<int> > even;

    vector<int> ans(n);

    forn(i, n) {
        if (used[i]) {
            continue;
        }
        if (i == p[i]) {
            ans[i] = i;
            continue;
        }
        vector<int> v;
        v.pb(i);
        used[i] = true;
        int j = p[i];
        while (true) {
            if (used[j]) {
                cout << "-1\n";
                return 0;
            }
            v.pb(j);
            used[j] = true;
            j = p[j];
            if (j == i) {
                break;
            }
        }
        if (sz(v) % 2 == 1) {
            int x = sz(v);
            int l = x / 2 + 1;
            for (int k = 0; k < x; ++k) {
                ans[v[k]] = v[(k + l) % x];
            }
        } else {
            even.pb(v);
        }
    }

    map<int, vector<vector<int> > > m;
    forn(i, sz(even)) {
        vector<int> &v = even[i];
        m[sz(v)].pb(v);
    }

    for (map<int, vector<vector<int> > >::iterator it = m.begin(); it != m.end(); ++it) {
        if (sz(it->second) % 2) {
            cout << "-1\n";
            return 0;
        }
        vector<vector<int> > &v = it->second;
        for (int i = 0; i < sz(v); i += 2) {
            int x = sz(v[i]);
            for (int j = 0; j < x; ++j) {
                ans[v[i][j]] = v[i + 1][j];
                ans[v[i + 1][j]] = v[i][(j + 1) % x];
            }
        }
    }

    forn(i, n) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");

}