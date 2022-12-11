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
typedef double ld;
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
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

const int nmax = 1e6 + 100;
const int kmax = 22;

int dp[nmax][kmax];
vector<int> divisors[nmax];
int fact[nmax];
int rfact[nmax];

int bin(int n, int k) {
    int ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 2; i < nmax; ++i) {
        divisors[i].pb(1);
        for (int j = i; j < nmax; j += i) {
            divisors[j].pb(i);
        }
    }

    dp[1][0] = 1;
    for (int i = 2; i < nmax; ++i) {
        for (int u = 1; u < kmax; ++u) {
            for (int j : divisors[i]) {
                if (j == i) {
                    continue;
                }
                add(dp[i][u], dp[j][u - 1]);
            }
        }
    }

    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    int tt;
    cin >> tt;

    while (tt--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int k = 1; k < kmax && k <= y; ++k) {
            int val = dp[x][k];
            //cout << k << " " << val << "\n";
            mul(val, bin(y, k));
            add(ans, val);
        }
        if (x == 1) {
            ans = 1;
        }
        mul(ans, binpow(2, y - 1));
        cout << ans << "\n";
    }

}