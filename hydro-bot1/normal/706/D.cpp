// Hydro submission #62c6d4f38672efa577c02176@1657197812434
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define mkp make_pair
#define no {cout << "-1"; return;}

struct Node {
    int to[2];
    int calc;

    Node() {
        to[0] = to[1] = calc = 0;
    }
};

vector<Node> trie(1);

void add(int v, int x, int bit) {
    if (bit == -1) {
        ++trie[v].calc;
        return;
    }

    bool f = (x & (1 << bit));
    if (!trie[v].to[f]) {
        trie[v].to[f] = trie.size();
        trie.push_back(Node());
    }

    add(trie[v].to[f], x, bit - 1);
}

bool del(int v, int x, int bit) {
    if (bit == -1) {
        --trie[v].calc;
        return !trie[v].calc;
    }

    bool f = (x & (1 << bit));
    bool emp = del(trie[v].to[f], x, bit - 1);

    if (emp) {
        trie[v].to[f] = 0;
        if (!trie[v].to[!f]) {
            return true;
        }
    }

    return false;
}

int get_ans(int v, int x, int bit) {
    if (bit == -1) {
        return 0;
    }

    bool f = !(x & (1 << bit));
    if (!trie[v].to[f]) {
        f = !f;
    }

    return get_ans(trie[v].to[f], x, bit - 1) + (1 << bit) * f;
}


void solve() {
    int q; cin >> q;
    add(0, 0, 30);

    loop(i, q) {
        char c; int x;
        cin >> c >> x;

        if (c == '+') {
            add(0, x, 30);
        }
        else if (c == '-') {
            del(0, x, 30);
        }
        else {
            cout << (x ^ get_ans(0, x, 30)) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}