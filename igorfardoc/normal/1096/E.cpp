#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int fact[maxn], rfact[maxn];
const int mod = 998244353;

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) res = ((ll)res * a) % mod;
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

void precalc() {
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) {
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

int func(int p, int s, int mx) {
    if(p == 0) {
        if(s == 0) return 1;
        return 0;
    }
    if(s < 0) return 0;
    int ans = 0;
    for(int i = 0; i <= p; i++) {
        int here = (ll)c(p, i) * c(p + s - i * mx - 1, p - 1) % mod;
        if(i % 2 == 0) {
            ans = (ans + here) % mod;
        } else {
            ans = (ans - here + mod) % mod;
        }
    }
    return ans;
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
    int p, s, r;
    cin >> p >> s >> r;
    int ans = 0;
    int down = 0;
    for(int i = r; i <= s; i++) {
        if(p != 1) {
            down = (down + c(p - 2 + s - i, p - 2)) % mod;
        } else {
            if(s == i) down = (down + 1) % mod;
        }
        for(int j = 0; j <= p - 1; j++) {
            ans = (ans + (ll)c(p - 1, j) * func(p - 1 - j, s - i * (j + 1), i) % mod * obr(j + 1)) % mod;
        }
    }
    cout << (ll)ans * obr(down) % mod;
}