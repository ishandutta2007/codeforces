#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int mod = 998244353;

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

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
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

const int nmax = 200500;

int t[2 * nmax];

void upd(int pos) {
    for (pos += nmax; pos; pos >>= 1) {
        ++t[pos];
    }
}

int get(int l, int r) {
    int ans = 0;
    for (l += nmax, r += nmax; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += t[l];
        }
        if (!(r & 1)) {
            ans += t[r];
        }
    }
    return ans;
}

int alive;

int solve(int p, int x) {
    //cout << p << " " << x << "\n";
    int ans = binpow(alive, mod - 2);
    mul(ans, p);
    mul(ans, x);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) {
            add(ans, get(a[i], n));
            upd(a[i]);
        }
    }

    alive = 0;
    for (int i = 1; i <= n; ++i) {
        if (!get(i, i)) {
            ++alive;
        }
    }

    if (alive == 0) {
        cout << ans << "\n";
        return 0;
    }

    int lf = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            int t = get(1, a[i]);
            //cout << "!" << alive << " " << a[i] << " " << t << endl;
            add(ans, solve(alive - lf, a[i] - t));
            add(ans, solve(lf, alive - (a[i] - t)));
        } else {
            ++lf;
        }
    }

    int val = alive;
    mul(val, alive - 1);
    mul(val, binpow(4, mod - 2));
    add(ans, val);

    cout << ans << "\n";

}