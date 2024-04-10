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

int N;
char S[100010];

int main() {
    
    
    for (; ~scanf("%s", S); ) {
        N = strlen(S);
        int m0 = count(S, S + N, '0');
        int m1 = count(S, S + N, '1');
        int x = count(S, S + N, '?');
        bool ans[4] = {};
        int t0 = (N - 2 + 1) / 2;
        int t1 = (N - 2 + 0) / 2;
        if (m1 <= t0) ans[0] = 1;
        if (m0 <= t1) ans[3] = 1;
        {
            int n0, n1, y, j;
            n0 = m0;
            n1 = m1;
            y = x;
            if (S[N - 1] == '?') {
                ++n0;
                --y;
            }
            if (S[N - 1] == '0' || S[N - 1] == '?') {
                for (j = 0; j <= y; ++j) {
                    if (n1 + j > t0 && n0 + (y - j) > t1) {
                        ans[2] = 1;
                    }
                }
            }
            n0 = m0;
            n1 = m1;
            y = x;
            if (S[N - 1] == '?') {
                ++n1;
                --y;
            }
//cout<<n0<<" "<<n1<<" "<<y<<endl;
            if (S[N - 1] == '1' || S[N - 1] == '?') {
                for (j = 0; j <= y; ++j) {
                    if (n1 + j > t0 && n0 + (y - j) > t1) {
                        ans[1] = 1;
                    }
                }
            }
        }
        if (ans[0]) puts("00");
        if (ans[1]) puts("01");
        if (ans[2]) puts("10");
        if (ans[3]) puts("11");
cerr<<"====="<<endl;
    }
    
    return 0;
}