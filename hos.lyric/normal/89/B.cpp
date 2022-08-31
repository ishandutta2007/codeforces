//  Codeforces Beta Round #74

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

char buf[100010];

int V;
map<string,int> tr;
int get(string s) {
    if (!tr.count(s)) tr[s] = V++;
    return tr[s];
}

char typ[110];
int X[110], Y[110];
int border[110], spacing[110];
vint packing[110];

bool memed[110];
Int xs[110], ys[110];

void calc(int u) {
    if (!memed[u]) {
        for (uint j = 0; j < packing[u].size(); ++j) {
            calc(packing[u][j]);
        }
        if (typ[u] == 'W') {
            xs[u] = X[u];
            ys[u] = Y[u];
        } else if (typ[u] == 'H') {
            xs[u] = ys[u] = 0;
            for (uint j = 0; j < packing[u].size(); ++j) {
                int v = packing[u][j];
                xs[u] += xs[v];
                chmax(ys[u], ys[v]);
            }
            if (packing[u].size()) {
                xs[u] += border[u] * 2;
                ys[u] += border[u] * 2;
                xs[u] += spacing[u] * (packing[u].size() - 1);
            }
        } else if (typ[u] == 'V') {
            xs[u] = ys[u] = 0;
            for (uint j = 0; j < packing[u].size(); ++j) {
                int v = packing[u][j];
                chmax(xs[u], xs[v]);
                ys[u] += ys[v];
            }
            if (packing[u].size()) {
                xs[u] += border[u] * 2;
                ys[u] += border[u] * 2;
                ys[u] += spacing[u] * (packing[u].size() - 1);
            }
        } else {
assert(0);
        }
        memed[u] = 1;
    }
}

int N;

int main() {
    int i;
    int u, v;
    
    for (; gets(buf); ) {
        N = atoi(buf);
        V = 0;
        tr.clear();
        memset(typ, 0, sizeof(typ));
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(border, 0, sizeof(border));
        memset(spacing, 0, sizeof(spacing));
        for (u = 0; u < 105; ++u) packing[u].clear();
        for (; N--; ) {
            gets(buf);
            if (isupper(buf[0])) {
                for (i = 0; buf[i]; ++i) if (buf[i] == '(' || buf[i] == ',' || buf[i] == ')') buf[i] = ' ';
                istringstream iss(buf);
                string s;
                iss >> s;
                iss >> s;
                u = get(s);
                typ[u] = buf[0];
                if (typ[u] == 'W') {
                    iss >> X[u] >> Y[u];
                }
            } else {
                for (i = 0; buf[i]; ++i) if (buf[i] == '.' || buf[i] == '(' || buf[i] == ')') buf[i] = ' ';
                istringstream iss(buf);
                string s, op;
                iss >> s >> op;
                u = get(s);
                if (op == "pack") {
                    string t;
                    iss >> t;
                    v = get(t);
                    packing[u].push_back(v);
                } else if (op == "set_border") {
                    iss >> border[u];
                } else if (op == "set_spacing") {
                    iss >> spacing[u];
                } else {
assert(0);
                }
            }
        }
        memset(memed, 0, sizeof(memed));
        for (map<string,int>::iterator it = tr.begin(), en = tr.end(); it != en; ++it) {
            string s = it->first;
            u = it->second;
            calc(u);
            cout << s << " " << xs[u] << " " << ys[u] << endl;
        }
    }
    
    return 0;
}