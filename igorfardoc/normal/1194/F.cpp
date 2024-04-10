#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int fact[300000], rfact[300000], p[300000];

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

int c(int n, int k) {
    if(n < 0 || k < 0 || k > n) return 0;
    int res = (ll)fact[n] * rfact[k] % mod;
    res = (ll)res * rfact[n - k] % mod;
    return res;
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
    fact[0] = 1;
    for(int i = 1; i < 300000; i++) {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    p[0] = 1;
    for(int i = 1; i < 300000; i++) {
        p[i] = p[i - 1] * 2 % mod;
    }
    int n;
    ll t;
    cin >> n >> t;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int curr = 1;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        t -= a[i];
        if(t < 0) break;
        int heremax = min(t, (ll)(i + 1));
        curr = ((ll)curr * 2 + c(i, mx + 1)) % mod;
        ++mx;
        while(mx > heremax) {
            curr = (curr - c(i + 1, mx) + mod) % mod;
            --mx;
        }
        //cout << (ll)curr * obr(p[i + 1]) % mod << endl;
        ans = (ans + (ll)curr * obr(p[i + 1])) % mod;
    }
    cout << ans;
}