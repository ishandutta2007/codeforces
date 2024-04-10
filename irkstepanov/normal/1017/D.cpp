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
typedef long double ld;
typedef pair<ld, ld> pld;

const int nmax = 12;

int n;
int w[nmax];
int sum[1 << nmax];

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int cnt[1 << nmax];

int convert(const string& s) {
    int val = 0;
    for (int i = n - 1; i >= 0; --i) {
        val <<= 1;
        val += (s[i] - '0');
    }
    return val;
}

const int kmax = 101;

int res[1 << nmax][kmax];

//mt19937 rr(random_device{}());

/*string gen() {
    string ans = "";
    for (int i = 0; i < n; ++i) {
        int r = rr() % 2;
        ans += char(r + '0');
    }
    return ans;
}*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    //n = 12;
    int m, q;
    cin >> m >> q;
    //m = q = 5e5;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        //w[i] = 10;
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        sum[mask] = 0;
        for (int i = 0; i < n; ++i) {
            if (!bit(mask, i)) {
                sum[mask] += w[i];
            }
        }
    }

    while (m--) {
        string s;
        cin >> s;
        //s = gen();
        ++cnt[convert(s)];
    }

    for (int a = 0; a < (1 << n); ++a) {
        for (int b = 0; b < (1 << n); ++b) {
            int x = (a ^ b);
            int z = sum[x];
            if (z < kmax) {
                res[a][z] += cnt[b];
            }
        }
    }

    while (q--) {
        string t;
        //t = gen();
        cin >> t;
        int val = convert(t);
        int ans = 0;
        int k;
        //k = 100;
        cin >> k;
        for (int i = 0; i <= k; ++i) {
            ans += res[val][i];
        }
        cout << ans << "\n";
    }

}