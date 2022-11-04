#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;

int bin_pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] + a[i - 1]) % mod;
    }
    for(int k = 1; k <= n; k++) {
        int now = n - 1 - k;
        int sum = 0;
        int it = 1;
        while(now >= 0) {
            int l = max(0, now - k + 1);
            int here = (pref[now + 1] - pref[l] + mod) % mod;
            sum = (sum + (ll)here * it) % mod;
            now = l - 1;
            ++it;
        }
        cout << ((ll)sum * obr(n)) % mod << ' ';
    }
}