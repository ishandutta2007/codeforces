#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 1e6 + 20;
int n, q;
int a[N];

vector <int> dv[N];
bool np[N];

int par[N];


void pre () {
    np[0] = np[1] = true;
    for (int i = 2; i < N; i++) {
        if (np[i]) continue;

        for (int j = i; j < N; j += i) {
            if (i != j) np[j] = true;
            dv[j].pb(i);
        }
    }

    memset(par, -1, sizeof par);
}

int root (int v) {
    return (par[v] < 0? v : par[v] = root(par[v]));
}

inline void merge (int u, int v) {
    if ((u = root(u)) == (v = root(v))) return;
    par[u] = v;
}

set <pii> st;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    pre();

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        for (int j = 0; j < _sz(dv[a[i]]) - 1; j++) {
            merge(dv[a[i]][j], dv[a[i]][j + 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        int r1 = root(dv[a[i]][0]);
        for (int x: dv[a[i] + 1]) {
            int r2 = root(x);
            if (r1 != r2) st.insert({r1, r2});

            for (int y: dv[a[i] + 1])
                if (x < y) {
                    int r3 = root(y);

                    if (r2 != r3) st.insert({r2, r3});
                }
        }
    }

    while (q--) {
        int s, t;
        cin >> s >> t;
        s--, t--;

        int r1 = root(dv[a[s]][0]), r2 = root(dv[a[t]][0]);
        
        if (r1 == r2) cout << 0 << '\n';
        else if (st.count({r1, r2}) || st.count({r2, r1})) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}