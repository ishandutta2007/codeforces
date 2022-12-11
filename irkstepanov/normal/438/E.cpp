#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
typedef complex<ld> comp;

const int mod = 998244353;
const int root = 31;
const int maxdeg = 23;
int proot[maxdeg + 1];
int rroot[maxdeg + 1];

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

vector<int> rev;

void fft(vector<int>& a, int k, bool flag) {
    int n = (1 << k);
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
        int omega = (flag ? rroot[r + 1] : proot[r + 1]);
        for (int i = 0; i < n; i += (1 << (r + 1))) {
            int p = 1;
            for (int j = 0; j < (1 << r); ++j) {
                int x = a[i + j], y = a[i + j + (1 << r)];
                mul(y, p);
                a[i + j] = x;
                add(a[i + j], y);
                a[i + j + (1 << r)] = x;
                sub(a[i + j + (1 << r)], y);
                mul(p, omega);
            }
        }
    }
    if (flag) {
        int rn = binpow(n, mod - 2);
        for (int i = 0; i < n; ++i) {
            mul(a[i], rn);
        }
    }
}

void mul(vector<int>& a, vector<int> b, int m, bool flag = false) {
    assert(sz(a) <= (1 << m) && sz(b) <= (1 << m));
    ++m;
    while (sz(a) < (1 << m)) {
        a.pb(0);
    }
    while (sz(b) < (1 << m)) {
        b.pb(0);
    }
    fft(a, m, false);
    fft(b, m, false);
    for (int i = 0; i < (1 << m); ++i) {
        mul(a[i], b[i]);
    }
    fft(a, m, true);
    if (flag) {
        a.resize((1 << (m - 1)));
    }
}

void mul(vector<int>& a, int b) {
    for (int i = 0; i < sz(a); ++i) {
        mul(a[i], b);
    }
}

void add(vector<int>& a, vector<int>& b) {
    while (sz(a) < sz(b)) {
        a.pb(0);
    }
    for (int i = 0; i < sz(b); ++i) {
        add(a[i], b[i]);
    }
}

void sub(vector<int>& a, vector<int>& b) {
    while (sz(a) < sz(b)) {
        a.pb(0);
    }
    for (int i = 0; i < sz(b); ++i) {
        sub(a[i], b[i]);
    }
}

void neg(vector<int>& a) {
    for (int i = 0; i < sz(a); ++i) {
        if (a[i]) {
            a[i] = mod - a[i];
        }
    }
}

void cont(vector<int>& p0, vector<int>& p1, vector<int>& q, int m, int pw) {
    /*cout << "INV\n";
    for (int x : p0) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : p1) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : q) {
        cout << x << " ";
    }
    cout << "\n";*/

    vector<int> b = p0;
    mul(b, q, pw, false);
    vector<int> r(m);
    for (int i = m; i < 2 * m; ++i) {
        r[i - m] = b[i];
    }

    vector<int> a = q;
    mul(a, p1, pw, true);
    neg(a);
    sub(a, r);
    mul(a, q, pw, true);
    for (int x : a) {
        q.pb(x);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    proot[maxdeg] = root;
    for (int i = maxdeg - 1; i >= 0; --i) {
        proot[i] = proot[i + 1];
        mul(proot[i], proot[i]);
    }
    for (int i = 0; i <= maxdeg; ++i) {
        rroot[i] = binpow(proot[i], mod - 2);
    }

    int n, M;
    cin >> n >> M;
    vector<int> c(M + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val > M) {
            continue;
        }
        c[val] = 1;
    }

    /*vector<int> dp(M + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (c[j] == 0) {
                continue;
            }
            for (int a = 0; a <= i - j; ++a) {
                int b = i - j - a;
                int val = dp[a];
                mul(val, dp[b]);
                add(dp[i], val);
            }
        }
    }*/

    int m = 1;
    vector<int> p = {1}; // p - 1 = p^2 q
    vector<int> q = {0}; // sum x^c_i
    vector<int> inv = {mod - 1}; // inv to (2pq - 1)

    int pw = 0;

    while (m <= M) {
        vector<int> b = p;
        mul(b, p, pw);
        vector<int> tmp = b;
        mul(b, q, pw + 1);
        vector<int> a = p;
        sub(a[0], 1);
        sub(a, b);
        vector<int> p1(m); // p1 = r
        for (int i = m; i < 2 * m; ++i) {
            p1[i - m] = a[i];
        }

        vector<int> q1(m);
        for (int i = m; i < 2 * m; ++i) {
            if (i <= M) {
                q1[i - m] = c[i];
            }
        }

        b = tmp;
        b.resize(m);
        mul(b, q1, pw, true);
        sub(p1, b);
        mul(p1, inv, pw, true);

        a = q;
        mul(a, p1, pw, true);
        b = q1;
        mul(b, p, pw, true);
        add(a, b);
        mul(a, 2);

        b = p;
        mul(b, q, pw, false);
        mul(b, 2);
        sub(b[0], 1);
        for (int i = m; i < 2 * m; ++i) {
            add(a[i - m], b[i]);
        }
        b.resize(m);

        cont(b, a, inv, m, pw);
        for (int x : p1) {
            p.pb(x);
        }
        for (int x : q1) {
            q.pb(x);
        }

        /*for (int x : inv) {
            cout << x << " ";
        }
        cout << endl;*/
        /*a = p;
        mul(a, q, pw + 1, true);
        mul(a, 2);
        sub(a[0], 1);
        mul(a, inv, pw + 1, true);
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";*/

        /*cout << m << ":\n";
        for (int x : q) {
            cout << x << " ";
        }
        cout << "\n";*/

        m *= 2;
        ++pw;
    }

    for (int i = 1; i <= M; ++i) {
        //assert(p[i] == dp[i]);
        //cout << p[i] << " " << dp[i] << endl;
        cout << p[i] << "\n";
    }
}