#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

pair<int, vector<string> > solve(int n, int m, vector<string> a) {
    char l[4] = {'A', 'C', 'G', 'T'};
    int opt = n * m + 1;
    vector<string> ans;

    for (int u = 0; u < 4; ++u) {
        for (int v = 0; v < 4; ++v) {
            if (u == v) {
                continue;
            }
            int uu = 0;
            while (uu == u || uu == v) {
                ++uu;
            }
            int vv = 6 - u - v - uu;
            int cnt = 0;
            vector<string> curr(n);
            for (int i = 0; i < n; ++i) {
                int x, y;
                if (i % 2 == 0) {
                    x = u, y = v;
                } else {
                    x = uu, y = vv;
                }
                int cx = 0, cy = 0;
                for (int j = 0; j < m; ++j) {
                    if ((j % 2 == 0) && a[i][j] != l[x]) {
                        ++cx;
                    }
                    if ((j % 2 == 0) && a[i][j] != l[y]) {
                        ++cy;
                    }
                    if ((j & 1) && a[i][j] != l[y]) {
                        ++cx;
                    }
                    if ((j & 1) && a[i][j] != l[x]) {
                        ++cy;
                    }
                }
                if (cx < cy) {
                    cnt += cx;
                    string s = "";
                    for (int j = 0; j < m; ++j) {
                        if (j % 2 == 0) {
                            s += l[x];
                        } else {
                            s += l[y];
                        }
                    }
                    curr[i] = s;
                } else {
                    cnt += cy;
                    string s = "";
                    for (int j = 0; j < m; ++j) {
                        if (j % 2 == 0) {
                            s += l[y];
                        } else {
                            s += l[x];
                        }
                    }
                    curr[i] = s;
                }
            }

            if (cnt < opt) {
                opt = cnt;
                ans = curr;
            }
        }
    }

    return {opt, ans};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    pair<int, vector<string> > ans1 = solve(n, m, a);
    vector<string> b(m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i] += a[j][i];
        }
    }

    pair<int, vector<string> > ans2 = solve(m, n, b);


    vector<string> res(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i] += ans2.second[j][i];
        }
    }
    ans2.second = res;

    if (ans1.first > ans2.first) {
        swap(ans1, ans2);
    }

    //cout << ans1.first << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans1.second[i] << "\n";
    }


}