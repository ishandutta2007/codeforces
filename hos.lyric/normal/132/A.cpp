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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

char S[110];

int main() {
    int i, j;
    
    for (; gets(S); ) {
        int bef = 0;
        for (i = 0; S[i]; ++i) {
            int tmp = 0;
            int c = S[i];
            for (j = 0; j < 8; ++j) if (c & 1 << j) {
                tmp |= 1 << (8 - 1 - j);
            }
            printf("%d\n", (bef - tmp) & 255);
            bef = tmp;
        }
    }
    
    return 0;
}