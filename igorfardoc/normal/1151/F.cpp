#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int fact[10000], rfact[10000];

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

void precalc() {
    fact[0] = 1;
    for(int i = 1; i < 10000; i++) {
        fact[i] = (ll)fact[i - 1] * i % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
}

int c(int n, int k) {
    if(n < 0 || k < 0 || k > n) return 0;
    int res = (ll)fact[n] * rfact[k] % mod;
    res = (ll)res * rfact[n - k] % mod;
    return res;
}

vvi mult(vvi& a, vvi& b) {
    vvi res(a.size(), vi(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            int here = 0;
            for(int k = 0; k < a[0].size(); k++) {
                here = (here + (ll)a[i][k] * b[k][j]) % mod;
            }
            res[i][j] = here;
        }
    }
    return res;
}

vvi bin_pow(vvi a, int st) {
    if(st == 0) {
        vvi res(a.size(), vi(a.size(), 0));
        for(int i = 0; i < a.size(); i++) {
            res[i][i] = 1;
        }
        return res;
    }
    auto mat = bin_pow(a, st >> 1);
    mat = mult(mat, mat);
    if(st & 1) {
        mat = mult(mat, a);
    }
    return mat;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    precalc();
    int n, k;
    cin >> n >> k;
    vi a(n);
    int am1 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]) {
            ++am1;
        }
    }
    int amgood = 0;
    for(int i = n - 1; i > n - 1 - am1; i--) {
        amgood += a[i];
    }
    int all = n * (n - 1) / 2;
    vvi start(1, vi(am1 + 1, 0));
    start[0][amgood] = 1;
    vvi mat(am1 + 1, vi(am1 + 1, 0));
    for(int i = 0; i <= am1; i++) {
        for(int j = 0; j <= am1; j++) {
            int now = j;
            int old = i;
            if(abs(now - old) > 1) continue;
            if(now == old) {
                int can = am1 * (am1 - 1) / 2;
                can = (can + (n - am1) * (n - am1 - 1) / 2) % mod;
                can = (can + now * (am1 - now)) % mod;
                can = (can + (am1 - now) * (n - 2 * am1 + now)) % mod; 
                mat[i][j] = (ll)can * obr(all) % mod;
            } else if(now > old) {
                int can = (am1 - old) * (am1 - old);
                mat[i][j] = (ll)can * obr(all) % mod;
            } else {
                int can = old * (n - 2 * am1 + old);
                mat[i][j] = (ll)can * obr(all) % mod;
            }
        }
    }
    auto mat1 = bin_pow(mat, k);
    auto res = mult(start, mat1);
    cout << res[0].back();
}