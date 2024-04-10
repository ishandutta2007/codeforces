#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int LOG = 20;

int n;
string s;
int dp[MAXN][2], val[MAXN];
int par[MAXN][LOG];
vector <pi> v;

void ubaci (int x, int ind) {
    while (!v.empty() && v.back().first < x) v.pop_back();
    if (!v.empty()) par[ind][0] = v.back().second;
    v.push_back({x, ind});
}

void precompute () {
    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < n; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
}

int nadi (int curr, int len) {
    if (val[curr] >= len) return curr;
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[curr][i] != 0 && val[par[curr][i]] < len) {
            curr = par[curr][i];
        }
    }
    return par[curr][0];
}

void solve (int len) {
    int curr = 1, sol = 0;
    while (curr <= n) {
        curr = nadi(curr, len);
        if (curr == 0) break;
        sol++;
        curr += len;
    }
    cout << sol << " ";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    s = '.' + s;
    for (int i = n; i >= 1; i--) {
        if (s[i] != '1') dp[i][0] = 1 + dp[i + 1][0];
        if (s[i] != '0') dp[i][1] = 1 + dp[i + 1][1];
        val[i] = max(dp[i][0], dp[i][1]);
        ubaci(val[i], i);
    }
    precompute();
    for (int i = 1; i <= n; i++) solve(i);
    return 0;
}