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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
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

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
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
    if (n < 0) {
        return 0;
    }
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
//

vector<int> operator*(const vector<int>& a, const vector<int>& b) {
    vector<int> c(sz(a) + sz(b), 0);
    for (int i = 0; i < sz(a); ++i) {
        for (int j = 0; j < sz(b); ++j) {
            int val = a[i];
            mul(val, b[j]);
            add(c[i + j], val);
        }
    }
    while (sz(c) > 1 && c.back() == 0) {
        c.pop_back();
    }
    return c;
}

const int kmax = 5050;

int ans[kmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ans[1] = binpow(2, n - 1);
    mul(ans[1], n);

    vector<int> poly = {0, 1};
    int pr = n;

    for (int k = 2; k < kmax; ++k) {
        vector<int> tmp = {mod - (k - 1), 1};
        poly = poly * tmp;
        mul(pr, n - (k - 1));
        int val = pr;
        mul(val, binpow(2, n - k));
        for (int i = 1; i < k; ++i) {
            int z = poly[i];
            mul(z, ans[i]);
            sub(val, z);
        }
        ans[k] = val;
    }

    int k;
    cin >> k;
    cout << ans[k] << endl;

}