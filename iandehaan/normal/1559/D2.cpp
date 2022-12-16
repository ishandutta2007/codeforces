#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

#define MAXN 100010

int n, m1, m2;

int par1[MAXN];
int par2[MAXN];

int compsize1[MAXN];
int compsize2[MAXN];

int biggestthing = 1;

int getPar1(int x) {
    if (par1[x] == x) return x;
    return par1[x] = getPar1(par1[x]);
}

int getPar2(int x) {
    if (par2[x] == x) return x;
    return par2[x] = getPar2(par2[x]);
}

void Union1(int x, int y) {
    if (getPar1(x) == getPar1(y)) return;
    compsize1[getPar1(y)] += compsize1[getPar1(x)];
    biggestthing = max(biggestthing, compsize1[getPar1(y)]);
    par1[getPar1(x)] = getPar1(y);
}

void Union2(int x, int y) {
    if (getPar2(x) == getPar2(y)) return;
    compsize2[getPar2(y)] += compsize2[getPar2(x)];
    biggestthing = max(biggestthing, compsize2[getPar2(y)]);
    par2[getPar2(x)] = getPar2(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < MAXN; i++) {
        par1[i] = i;
        par2[i] = i;
        compsize1[i] = 1;
        compsize2[i] = 1;
    }

    cin >> n >> m1 >> m2;

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Union1(u, v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Union2(u, v);
    }

    vector<pair<int, int>> out;

    // do this until there is something of size n-100
    while (true) {
        if (biggestthing > n-100) break;
        int i = rng() % n;
        int j = rng() % n;

        //cout << "random with " << i << ' ' << j << endl;

        if (getPar1(i) != getPar1(j) && getPar2(i) != getPar2(j)) {
            out.pb(mp(i+1, j+1));
            Union1(i, j);
            Union2(i, j);
        }
    }

    // find what's left out
    vector<int> specials;
    for (int i = 0; i < n; i++) {
        if (compsize1[getPar1(i)] > n-100) {
           int specialpar = getPar1(i);
           for (int j = 0; j < n; j++) {
               if (getPar1(j) != specialpar) specials.pb(j);
           } 
           break;
        }

        if (compsize2[getPar2(i)] > n-100) {
           int specialpar = getPar2(i);
           for (int j = 0; j < n; j++) {
               if (getPar2(j) != specialpar) specials.pb(j);
           } 
           break;
        }
    }

    //cout << sz(specials) << "lol" << endl;

    for (int i : specials) {
        //cout << "special " << i+1 << endl;
        for (int j = 0; j < n; j++) {
            if (getPar1(i) != getPar1(j) && getPar2(i) != getPar2(j)) {
                out.pb(mp(i+1, j+1));
                Union1(i, j);
                Union2(i, j);
            }
        }
    }

    cout << sz(out) << endl;
    for (pair<int, int> edge : out) {
        cout << edge.first << ' ' << edge.second << endl;
    }
}