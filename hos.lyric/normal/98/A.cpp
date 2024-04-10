//  Codeforces Beta Round #78

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

void rot(string &a, int i, int j) { int ttt = a[i]; a[i] = a[j]; a[j] = a[5 - i]; a[5 - i] = a[5 - j]; a[5 - j] = ttt; }
void rotX(string &a) { rot(a, 1, 2); }
void rotY(string &a) { rot(a, 2, 0); }
void rotZ(string &a) { rot(a, 0, 1); }

string smallest(string a) {
    int i;
    string ret = a;
    for (i = 0; i < 24; ++i) {
        chmin(ret, a);
        rotZ(a);
        if (i % 8 == 3) rotX(a);
        if (i % 8 == 7) rotY(a);
    }
    return ret;
}

string S;

int main() {
    
    
    for (; cin >> S; ) {
        sort(S.begin(), S.end());
        set<string> ss;
        do {
            ss.insert(smallest(S));
        } while (next_permutation(S.begin(), S.end()));
        cout << ss.size() << endl;
    }
    
    return 0;
}