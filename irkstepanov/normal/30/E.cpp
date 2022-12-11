#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const int rmax = 20;

vector<vector<int> > sparse;
vector<int> deg;

int get(int l, int r)
{
    int len = r - l + 1;
    int d = deg[len];
    //cout << "GET " << l << " " << r << " RES " << max(sparse[l][d], sparse[r - (1 << d) + 1][d]) << "\n";
    return max(sparse[l][d], sparse[r - (1 << d) + 1][d]);
}

vector<int> z_func(const string& s)
{
    int n = sz(s);
    vector<int> z(n);
    for (int i = 1, l = 0, r = -1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int magic(int l, int r)
{
    int lf = 0, rg = r - l + 1;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        int L = l + md - 1, R = r - md + 1;
        if (L > R) {
            rg = md;
            continue;
        }
        int s = get(L, R);
        if (s >= md) {
            lf = md;
        } else {
            rg = md;
        }
    }
    return lf;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;

    deg.resize(100500);
    deg[1] = 0;
    for (int i = 2; i < 100500; ++i) {
        deg[i] = deg[i - 1];
        if (!(i & (i - 1))) {
            ++deg[i];
        }
    }

    int n = sz(s);
    vector<int> d(n);

    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        if (i <= r) {
            d[i] = min(r - i + 1, d[r + l - i]);
        }
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]) {
            ++d[i];
        }
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }

    sparse.resize(n);
    for (int i = 0; i < n; ++i) {
        sparse[i].resize(rmax);
        sparse[i][0] = d[i];
    }
    for (int r = 1; r < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            int t = i + (1 << (r - 1));
            if (t >= n) {
                t = n - 1;
            }
            sparse[i][r] = max(sparse[i][r - 1], sparse[t][r - 1]);
        }
    }

    string t = s;
    reverse(all(t));
    t += "#" + s;

    vector<int> p = z_func(t);

    vector<int> beg(n + 1, -1);
    for (int i = sz(s) + 1; i < sz(t); ++i) {
        //cout << "!" << i << " " << p[i] << "\n";
        if (beg[p[i]] == -1) {
            beg[p[i]] = i - sz(s) - 1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (beg[i + 1] != -1) {
            if (beg[i] == -1) {
                beg[i] = beg[i + 1];
            } else {
                beg[i] = min(beg[i], beg[i + 1]);
            }
        }
    }

    int ans = 0;
    int ax = -1, lx, ay = -1, ly, az = -1, lz;
    for (int i = 0; i < n; ++i) {
        if (d[i] > ans) {
            ans = d[i];
            ay = i - d[i] + 1;
            ly = 2 * d[i] - 1;
        }
    }

    for (int i = 1; i <= n; ++i) { // len of suff
        if (beg[i] == -1) {
            continue;
        }
        //cout << i << " " << beg[i] << "\n";
        int l = beg[i] + i;
        int r = n - i - 1;
        if (l > r) {
            continue;
        }
        int x = magic(l, r);
        //cout << x << "\n";
        if (2 * i + 2 * x - 1 > ans) {
            ans = 2 * i + 2 * x - 1;
            ax = beg[i], lx = i;
            az = n - i, lz = i;
            ly = x;
        }
    }

    if (ax != -1) {
        int l = ax + lx, r = az - 1;
        for (int i = l + ly - 1; i <= r - ly + 1; ++i) {
            if (d[i] >= ly) {
                ay = i - ly + 1;
            }
        }
        ly = 2 * ly - 1;
    }

    int cnt = 0;
    if (ax != -1) {
        ++cnt;
    }
    if (ay != -1) {
        ++cnt;
    }
    if (az != -1) {
        ++cnt;
    }
    cout << cnt << "\n";
    if (ax != -1) {
        cout << ax + 1 << " " << lx << "\n";
    }
    if (ay != -1) {
        cout << ay + 1 << " " << ly << "\n";
    }
    if (az != -1) {
        cout << az + 1 << " " << lz << "\n";
    }

}