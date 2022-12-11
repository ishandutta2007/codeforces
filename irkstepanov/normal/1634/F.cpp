#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int mod;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

vector<int> d;
int cnt = 0;
int n;

void upd(int pos, int val) {
    if (pos >= n) {
        return;
    }
    if (d[pos]) {
        --cnt;
    }
    add(d[pos], val);
    if (d[pos]) {
        ++cnt;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int q;
    cin >> n >> q >> mod;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sub(c[i], x);
    }

    d.resize(n);

    d[0] = c[0];
    if (d[0]) {
        ++cnt;
    }

    if (n >= 2) {
        d[1] = c[1];
        sub(d[1], c[0]);
        if (d[1]) {
            ++cnt;
        }
    }

    for (int i = 2; i < n; ++i) {
        d[i] = c[i];
        sub(d[i], c[i - 1]);
        sub(d[i], c[i - 2]);
        if (d[i]) {
            ++cnt;
        }
    }

    vector<vector<int> > f(2, vector<int>(n + 1));

    f[0][1] = 1 % mod;
    f[0][2] = 1 % mod;
    for (int i = 3; i <= n; ++i) {
        f[0][i] = f[0][i - 1];
        add(f[0][i], f[0][i - 2]);
    }

    for (int i = 1; i <= n; ++i) {
        f[1][i] = 0;
        sub(f[1][i], f[0][i]);
    }

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        int p = (c == 'A' ? 0 : 1);
        --l, --r;
        int k = r - l + 1;
        upd(l, f[p][1]);
        if (k >= 2) {
            int val = 0;
            sub(val, f[p][k]);
            upd(r + 2, val);
            sub(val, f[p][k - 1]);
            upd(r + 1, val);
        } else {
            int val = 0;
            sub(val, f[p][k]);
            upd(r + 1, val);
            upd(r + 2, val);
        }
        cout << (cnt == 0 ? "YES" : "NO") << "\n";
    }

}