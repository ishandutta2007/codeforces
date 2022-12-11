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
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct node {
    int left;
    int right;
    int cnt;
    node() : left(-1), right(-1), cnt(0) {}
};

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

vector<node> t;
const int rmax = 30;

void add(int val) {
    int v = 0;
    ++t[v].cnt;
    for (int r = rmax - 1; r >= 0; --r) {
        if (bit(val, r)) {
            if (t[v].right == -1) {
                t[v].right = sz(t);
                t.pb(node());
            }
            v = t[v].right;
        } else {
            if (t[v].left == -1) {
                t[v].left = sz(t);
                t.pb(node());
            }
            v = t[v].left;
        }
        ++t[v].cnt;
    }
}

void del(int val) {
    int v = 0;
    --t[v].cnt;
    for (int r = rmax - 1; r >= 0; --r) {
        if (bit(val, r)) {
            v = t[v].right;
        } else {
            v = t[v].left;
        }
        --t[v].cnt;
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

    t.pb(node());

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        add(b[i]);
    }

    for (int i = 0; i < n; ++i) {
        int v = 0;
        int res = 0;
        int val = 0;
        for (int r = rmax - 1; r >= 0; --r) {
            if (bit(a[i], r)) {
                if (t[v].right != -1 && t[t[v].right].cnt) {
                    v = t[v].right;
                    val ^= (1 << r);
                } else {
                    v = t[v].left;
                    res ^= (1 << r);
                }
            } else {
                if (t[v].left != -1 && t[t[v].left].cnt) {
                    v = t[v].left;
                } else {
                    v = t[v].right;
                    val ^= (1 << r);
                    res ^= (1 << r);
                }
            }
        }
        cout << res << " ";
        del(val);
    }
    cout << "\n";

}