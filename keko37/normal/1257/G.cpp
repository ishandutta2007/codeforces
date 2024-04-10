#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 300005;
const int LOG = 18;
const int MOD = 998244353;

int n, br, g = 3, root_pw = (1 << 23);
int pot[MAXN], inv[MAXN], ind[MAXN];
map <int, int> mp;
vector <int> v[MAXN];

int mul (int x, int y) {return 1LL * x * y % MOD;}
int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}

int bpow (int a, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void precompute () {
    int curr = bpow(3, 119);
    for (int m = root_pw; m >= 2; m /= 2) {
        if (m < MAXN) {
            pot[m] = curr;
            inv[m] = bpow(pot[m], MOD - 2);
        }
        curr = mul(curr, curr);
    }
}

void fft (vector <int> & a, bool invert) {
    int m = a.size();
    if (m == 1) return;
    vector <int> a0(m / 2), a1(m / 2);
    int half = m / 2;
    for (int i = 0; i < half; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    int w = 1, wn = (invert ? pot[m] : inv[m]);
    for (int i = 0; i < half; i++) {
        a[i] = add(a0[i], mul(w, a1[i]));
        a[i + half] = sub(a0[i], mul(w, a1[i]));
        if (invert) {
            a[i] = mul(a[i], (MOD + 1) / 2);
            a[i + half] = mul(a[i + half], (MOD + 1) / 2);
        }
        w = mul(w, wn);
    }
}

void ispis (vector <int> r) {
    for (auto x : r) cout << x << " "; cout << endl;
}

void mnozi (vector <int> & a, vector <int> & b) {
    int m = 1;
    while (m < a.size() + b.size()) m *= 2;
    a.resize(m); b.resize(m);
    fft(a, 0); fft(b, 0);
    for (int i = 0; i < m; i++) {
        a[i] = mul(a[i], b[i]);
    }
    fft(a, 1);
    while (a.back() == 0) a.pop_back();
}

void dvc (int lo, int hi) {
    if (lo == hi) return;
    int mid = (lo + hi) / 2;
    dvc(lo, mid);
    dvc(mid + 1, hi);
    mnozi(v[lo], v[mid + 1]);
}

int main () {
    precompute();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        mp[p]++;
    }
    for (auto par : mp) {
        v[br++].resize(par.second + 1, 1);
    }
    dvc(0, br - 1);
    cout << v[0][n / 2];
    return 0;
}