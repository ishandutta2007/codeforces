//  Codeforces Beta Round #77

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

int N, L;
string S[110];
string T;
char C;
int is[1010];

string TOLOWER(string s) {
    string ret = "";
    for (uint i = 0; i < s.size(); ++i) ret += tolower(s[i]);
    return ret;
}

int main() {
    int i, j;
    
    for (; cin >> N; ) {
        for (i = 0; i < N; ++i) {
            cin >> S[i];
        }
        cin >> T;
        cin >> C;
        L = T.size();
        memset(is, 0, sizeof(is));
        for (i = 0; i < N; ++i) for (j = 0; j + (int)S[i].size() <= L; ++j) {
            if (TOLOWER(S[i]) == TOLOWER(T.substr(j, S[i].size()))) {
                ++is[j];
                --is[j + S[i].size()];
            }
        }
        for (j = 0; j < L; ++j) {
            is[j + 1] += is[j];
        }
        string ans = T;
        for (j = 0; j < L; ++j) if (is[j]) {
            bool up = isupper(T[j]);
            char c = tolower(C);
            char d = tolower(T[j]);
            char e;
            if (d != c) {
                e = c;
            } else if (d != 'a') {
                e = 'a';
            } else {
                e = 'b';
            }
            if (up) e = toupper(e);
            ans[j] = e;
        }
        cout << ans << endl;
    }
    
    return 0;
}