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
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e6 + 100;
int g[nmax];
int cnt[nmax][10];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 1; i < nmax; ++i) {
        if (i < 10) {
            g[i] = i;
            continue;
        }
        int n = i;
        int p = 1;
        while (n) {
            if (n % 10) {
                p *= (n % 10);
            }
            n /= 10;
        }
        assert(p < i);
        g[i] = g[p];
    }

    for (int i = 1; i < nmax; ++i) {
        for (int j = 0; j < 10; ++j) {
            cnt[i][j] = cnt[i - 1][j];
        }
        ++cnt[i][g[i]];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = cnt[r][k] - cnt[l - 1][k];
        cout << ans << "\n";
    }

}