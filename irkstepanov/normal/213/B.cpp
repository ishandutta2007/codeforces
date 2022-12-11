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
        n >>= 1;
        mul(a, a);
    }
    return ans;
}

const int nmax = 200;
int fact[nmax];
int rfact[nmax];
int rev[10 * nmax];

int solve(int n, vector<int> a) {
    int m = 1;
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        mul(m, rfact[a[i]]);
        sum += a[i];
    }
    if (sum > n) {
        return 0;
    }
    mul(m, fact[sum]);
    vector<vector<int> > v(10, vector<int>(nmax));
    int p = 1;
    v[0][0] = p;
    for (int j = 1; j < nmax; ++j) {
        mul(p, rev[a[0] + j]);
        v[0][j] = p;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < nmax; ++j) {
            p = v[i][j];
            add(v[i + 1][j], p);
            for (int t = 1; t + j < nmax; ++t) {
                mul(p, rev[a[i + 1] + t]);
                add(v[i + 1][t + j], p);
            }
        }
    }
    p = 1;
    int ans = 0;
    add(ans, 1);
    for (int j = 1; j <= n - sum; ++j) {
        mul(p, sum + j);
        int val = p;
        mul(val, v[9][j]);
        add(ans, val);
    }
    mul(ans, m);
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

    fact[0] = rfact[0] = 1;
    for (int i = 1; i < nmax; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }
    for (int i = 1; i < 10 * nmax; ++i) {
        rev[i] = binpow(i, mod - 2);
    }

	int n;
    cin >> n;

    vector<int> a(10);
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    /*bool zero = true;
    for (int i = 1; i < 10; ++i) {
        if (a[i]) {
            zero = false;
        }
    }
    if (a[0] > 1) {
        zero = false;
    }
    if (zero) {
        ans = 1;
    }*/

    for (int d = 1; d < 10; ++d) {
        vector<int> b = a;
        --b[d];
        if (b[d] < 0) {
            b[d] = 0;
        }
        add(ans, solve(n - 1, b));
    }

    cout << ans << "\n";

}