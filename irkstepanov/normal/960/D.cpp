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
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int rmax = 70;

void upd(ll& val, int level, ll x) {
    ll mod = (1LL << level);
    x %= mod;
    val += x;
    if (val >= mod) {
        val -= mod;
    } else if (val < 0) {
        val += mod;
    }
}

vector<ll> a(rmax);
vector<ll> b(rmax);

ll getVal(int level, ll pos) {
    upd(pos, level, -a[level]);
    pos += (1LL << level);
    return pos;
}

void solve(ll pos, int level) {
    cout << getVal(level, pos) << " ";
    if (level == 0) {
        cout << "\n";
        return;
    }
    ll val = (pos >> 1);
    upd(val, level - 1, b[level - 1]);
    solve(val, level - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        ll x;
        cin >> x;
        ll oldX = x;
        int level = -1;
        while (x) {
            ++level;
            x >>= 1;
        }
        x = oldX;
        if (type == 1) {
            ll k;
            cin >> k;
            upd(a[level], level, k);
        } else if (type == 2) {
            ll k;
            cin >> k;
            upd(a[level], level, k);
            upd(b[level], level, k);
        } else {
            ll pos = x - (1LL << level);
            upd(pos, level, a[level]);
            solve(pos, level);
        }
    }

}