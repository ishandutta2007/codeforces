#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct Fraction {
    ll num, den;
    Fraction() : num(0), den(1) {}
    Fraction(ll x, ll y) : num(x), den(y) {}
    bool operator<(const Fraction& other) const {
        return num * other.den < den * other.num;
    }
};

bool comp(const pii& a, const pii& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

ll get(int lf, int rg, const vector<ll>& pref) {
    if (lf > rg) {
        return 0;
    }
    ll ans = pref[rg];
    if (lf - 1 >= 0) {
        ans -= pref[lf - 1];
    }
    return ans;
}

const int nmax = 55;
const int dmax = 110 * 55 + 10;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }

    sort(all(a), comp);

    vector<ll> p1(n);
    p1[0] = a[0].first;
    for (int i = 1; i < n; ++i) {
        p1[i] = p1[i - 1] + a[i].first;
    }

    vector<ll> p2(n);
    p2[0] = a[0].second;
    for (int i = 1; i < n; ++i) {
        p2[i] = p2[i - 1] + a[i].second;
    }

    vector<vector<ll> > dp(nmax, vector<ll>(dmax, -1));
    dp[0][0] = 0;

    int ptr = 0;
    while (ptr < n) {
        int lf = ptr;
        int rg = ptr;
        while (rg + 1 < sz(a) && a[rg + 1].first == a[rg].first) {
            ++rg;
        }
        vector<vector<ll> > nx(nmax, vector<ll>(dmax, -1));
        for (int s = 0; s <= n; ++s) {
            for (int d = 0; d < dmax; ++d) {
                if (dp[s][d] == -1) {
                    continue;
                }
                for (int z = 0; z <= s && z <= rg - lf + 1; ++z) {
                    ll x = dp[s][d], y = d;
                    x += get(lf + z, rg, p1);
                    y += get(lf + z, rg, p2);
                    int r = s - z + (rg - lf + 1 - z);
                    if (nx[r][y] == -1 || x < nx[r][y]) {
                        nx[r][y] = x;
                    }
                }
            }
        }
        dp.swap(nx);
        ptr = rg + 1;
    }

    Fraction ans = Fraction(-1, 1);
    for (int s = 0; s <= n; ++s) {
        for (int d = 0; d < dmax; ++d) {
            if (dp[s][d] == -1) {
                continue;
            }
            Fraction val = Fraction(dp[s][d], d);
            if (ans.num == -1 || val < ans) {
                ans = val;
            }
        }
    }

    ll x = ans.num, y = ans.den;
    x *= 1000;
    //cout << x << " " << y << endl;
    cout << (x + y - 1) / y << "\n";

}