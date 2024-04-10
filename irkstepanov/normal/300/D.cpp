#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef complex<ld> comp;

const int mod = 7340033;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

int root = 5;
vector<int> rev;
int magic[21];
int rmagic[21];
const int rr = 12;
const int kmax = (1 << rr);
int rn = binpow(kmax, mod - 2);

void fft(vector<int>& a, int k, bool flag) {
    int n = (1 << k);
    assert(n == kmax);
    assert(sz(a) == n);
    if (sz(rev) != n) {
        rev = vector<int>(n);
        int oldest = -1;
        rev[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (!(i & (i - 1))) {
                ++oldest;
            }
            rev[i] = rev[i ^ (1 << oldest)] + (1 << (k - oldest - 1));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rev[i] < i) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int r = 0; r < k; ++r) {
        int omega = (flag ? rmagic[r + 1] : magic[r + 1]);
        int p = 1;
        for (int j = 0; j < (1 << r); ++j) {
            for (int i = j; i < n; i += (1 << (r + 1))) {
                int x = a[i], y = a[i + (1 << r)];
                mul(y, p);
                a[i] = x;
                add(a[i], y);
                a[i + (1 << r)] = x;
                sub(a[i + (1 << r)], y);
            }
            mul(p, omega);
        }
    }
    if (flag) {
        for (int i = 0; i < n; ++i) {
            mul(a[i], rn);
        }
    }
}

map<int, vector<int> > mapa;

vector<int> solve(int cnt) {
    if (cnt == 0) {
        vector<int> ans(kmax, 0);
        ans[0] = 1;
        mapa[cnt] = ans;
        return ans;
    }
    vector<int> vct = solve(cnt - 1);
    fft(vct, rr, false);
    for (int i = 0; i < kmax; ++i) {
        mul(vct[i], vct[i]);
        mul(vct[i], vct[i]);
    }
    fft(vct, rr, true);
    for (int i = kmax - 1; i >= 1; --i) {
        vct[i] = vct[i - 1];
    }
    vct[0] = 1;
    for (int i = 1001; i < kmax; ++i) {
        vct[i] = 0;
    }
    mapa[cnt] = vct;
    return vct;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    magic[20] = root;
    for (int i = 19; i >= 0; --i) {
        magic[i] = magic[i + 1];
        mul(magic[i], magic[i]);
    }
    for (int i = 0; i <= 20; ++i) {
        rmagic[i] = binpow(magic[i], mod - 2);
    }

    solve(35);

    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;
        int num = 0;
        while (n > 1 && (n % 2) == 1) {
            ++num;
            n /= 2;
        }
        vector<int> ans = mapa[num];
        cout << ans[k] << "\n";
    }

}