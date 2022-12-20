#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long double inf = 1e9 + 1;
const long double pi = 3.14159265358979323846;
const int N = 3e5;

string s[N];
vector <int> d[N];

int main() {
    int  i, j, n, k, q, l, r, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> q;
    for (i = 0; i < n; ++i) {
        cin >> s[i];
        d[i].resize(k);
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
    if (d[i][j] == 0 && s[i][j] == '.') {
        vector <pair<int, int> > v;
        v.push_back({i, j});
        int ans = 0;
        d[i][j] = -1;
        for (l = 0; l < v.size(); ++l) {
            for (int i1 = -1; i1 <= 1; ++i1)
            for (int j1 = -1; j1 <= 1; ++j1)
            if (abs(i1) + abs(j1) == 1)
                if (s[v[l].fi + i1][v[l].se + j1] == '*')
                    ++ans;
                else  {
                        if (d[v[l].fi + i1][v[l].se + j1] == 0) {
                            d[v[l].fi + i1][v[l].se + j1] = -1;
                            v.push_back({v[l].fi + i1, v[l].se + j1});
                        }
                    }
        }
        for (l = 0; l < v.size(); ++l)
            d[v[l].fi][v[l].se] = ans;
    }
    for (i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << d[a - 1][b - 1] << "\n";
    }
}