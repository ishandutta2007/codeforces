#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int fact[10000], rfact[10000];
const int mod = 998244353;
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

int c(int n, int k) {
    if(n < 0 || k < 0 || k > n) {
        return 0;
    }
    int res = ((ll)fact[n] * rfact[k]) % mod;
    res = ((ll)res * rfact[n - k]) % mod;
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
    for(int i = 1; i < 10000; i++) {
        fact[i] = ((ll)fact[i - 1] * i) % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k == 0) {
        cout << 1;
        return 0;
    }
    vi pos;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            pos.push_back(i);
        }
    }
    if(pos.size() < k) {
        cout << 1;
        return 0;
    }
    int ans = 1;
    for(int i = 0; i < pos.size(); i++) {
        int after = min(k - 1, (int)pos.size() - i - 1);
        int end = i + after;
        int r = n - 1;
        if(end != pos.size() - 1) {
            r = pos[end + 1] - 1;
        }
        int l = 0;
        if(i != 0) {
            l = pos[i - 1] + 1;
        }
        //cout << pos[i] << ' ' << l << ' ' << r << ' ' << after << endl;
        for(int j = l; j <= r; j++) {
            if(j == pos[i]) continue;
            ans = (ans + c(r - j, after)) % mod;
        }
    }
    cout << ans;
    /*
    vvi dp(n + 1, vi(k + 1, 0));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if(i == 0) {
                dp[i][j] = 1;
                continue;
            }
    */


}