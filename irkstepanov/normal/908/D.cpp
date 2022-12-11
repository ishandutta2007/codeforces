#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

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

int binpow(int a, int n) {
    int ans = 1;
    assert(a != 0);
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k, pa, pb;
    cin >> k >> pa >> pb;

    int den = binpow(pa + pb, mod - 2);
    int x = pa;
    mul(x, den);
    int y = pb;
    mul(y, den);

    vector<vector<int> > dp(k + 1, vector<int>(k));
    int revx = 1;
    sub(revx, x);
    //assert(revx == y);
    revx = binpow(revx, mod - 2);
    for (int i = 0; i < k; ++i) {
        int val = i + k;
        mul(val, y);
        mul(val, revx);
        add(dp[k][i], val);
        val = y;
        mul(val, x);
        mul(val, revx);
        mul(val, revx);
        add(dp[k][i], val);
    }

    for (int cnta = k - 1; cnta >= 1; --cnta) {
        for (int s = k - 1; s >= 0; --s) {
            int val = x;
            mul(val, dp[cnta + 1][s]);
            add(dp[cnta][s], val);
            val = y;
            if (s + cnta >= k) {
                mul(val, s + cnta);
                add(dp[cnta][s], val);
            } else {
                mul(val, dp[cnta][s + cnta]);
                add(dp[cnta][s], val);
            }
        }
    }

    cout << dp[1][0] << "\n";

}