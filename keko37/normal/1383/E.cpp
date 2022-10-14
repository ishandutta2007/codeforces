#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int MOD = 1000000007;

int n, curr, ima, br;
string s;
int dp[MAXN];
vector <pi> v;
vector <int> r;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void makni () {
    int len = v.back().first, pos = v.back().second;
    curr = sub(curr, dp[pos]);
    v.pop_back();
    if (!v.empty()) {
        curr = sub(curr, dp[v.back().second - len - 1]);
        curr = add(curr, dp[v.back().second]);
    }
}

void ubaci (int len, int pos) {
    while (!v.empty() && v.back().first <= len) makni();
    if (!v.empty()) {
        curr = sub(curr, dp[v.back().second]);
        curr = add(curr, dp[v.back().second - len - 1]);
    }
    v.push_back({len, pos});
    curr = add(curr, dp[pos]);
}

void calc (int lo, int hi) {
    //if (hi == n-1) cout << curr << " " << dp[lo - 1] << endl;
    dp[lo] = add(br + 1, curr);
    int novi = curr;
    if (!v.empty()) novi = add(sub(novi, dp[v.back().second]), dp[v.back().second - 1]);
    int a = 0, b = 0;
    for (int i = lo + 1; i <= hi; i++) {
        if (s[i] == '1') {
            a++;
            dp[i] = add(dp[i - 1], add(novi, br + 1));
        } else {
            b++;
            dp[i] = mul(dp[lo + a], (b + 1));
        }
    }
    ubaci(b, hi);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && ima == 0) br++;
        if (s[i] == '1') ima = 1;
        if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) r.push_back(i);
    }
    if (ima == 0) {
        cout << n;
        return 0;
    }
    r.push_back(n);
    for (int i = 1; i < r.size(); i++) {
        calc(r[i - 1], r[i] - 1);
    }
    cout << dp[n - 1];
    return 0;
}