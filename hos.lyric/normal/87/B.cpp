//  Codeforces Beta Round #73

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

const int INF = 1001001001;

int N;
map<string,int> is;
char A[1010], B[1010], C[1010];

int main() {
    int m, i, j;
    
    for (; ~scanf("%d", &N); ) {
        is.clear();
        is["void"] = 0;
        is["errtype"] = -INF;
        for (; N--; ) {
            scanf("%s%s", A, B);
            m = strlen(B);
            for (i = 0; B[i] == '&'; ++i);
            for (j = 0; B[m - 1 - j] == '*'; ++j);
            string s = string(B).substr(i, m - i - j);
            int a = is.count(s) ? is[s] : -INF;
            a += j - i;
            if (a < 0) a = -INF;
            if (!strcmp(A, "typedef")) {
                scanf("%s", C);
//cout<<C<<" := "<<a<<endl;
                is[C] = a;
            } else {
                if (a < 0) {
                    puts("errtype");
                } else {
                    printf("void%s\n", string(a, '*').c_str());
                }
            }
        }
    }
    
    return 0;
}