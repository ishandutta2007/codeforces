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

#define MAX 10010

char buf[10010];

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int N, K;
string S[MAX][4];
string T[MAX][4];
bool is[MAX][4][4];

int main() {
    int i;
    int x, y;
    bool aabb, abab, abba;
    
    for (; ~scanf("%d%d", &N, &K); ) {
        for (i = 0; i < N; ++i) {
            for (x = 0; x < 4; ++x) {
                scanf("%s", buf);
                S[i][x] = buf;
            }
        }
        for (i = 0; i < N; ++i) {
            for (x = 0; x < 4; ++x) {
                int sz = S[i][x].size(), j;
                int k = 0;
                for (j = sz; j--; ) if (isVowel(S[i][x][j])) {
                    if (++k == K) {
                        T[i][x] = S[i][x].substr(j);
                        break;
                    }
                }
                if (k < K) {
                    goto failed;
                }
            }
        }
        for (i = 0; i < N; ++i) {
            for (x = 0; x < 4; ++x) for (y = 0; y < 4; ++y) {
                is[i][x][y] = (T[i][x] == T[i][y]);
            }
        }
        aabb = abab = abba = 1;
        for (i = 0; i < N; ++i) {
            aabb = aabb && is[i][0][1] && is[i][2][3];
            abab = abab && is[i][0][2] && is[i][1][3];
            abba = abba && is[i][0][3] && is[i][1][2];
        }
        if (!aabb && !abab && !abba) {
            goto failed;
        } else if (aabb && abab && abba) {
            puts("aaaa");
        } else {
            if (aabb) puts("aabb");
            if (abab) puts("abab");
            if (abba) puts("abba");
        }
        continue;
    failed:;
        puts("NO");
    }
    
    return 0;
}