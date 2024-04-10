//  UOI 2011.04.12.

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

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t > f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

typedef unsigned long long UInt;

const int N = 64;
UInt A, B;

int main() {
    int i;
    
    for (; cin >> A >> B; ) {
        UInt a = A;
        UInt x = 0, y = 0;
        for (i = 0; i < N; ++i) {
            UInt two = 1ULL << i;
            if (B & two) {
                if (a < two) goto failed;
                a -= two;
                y += two;
            }
        }
//cout<<a<<" "<<x<<" "<<y<<endl;
        if (a % 2 != 0) goto failed;
        for (i = 0; i < N - 1; ++i) {
            UInt two = 1ULL << i;
            a /= 2;
            if (a % 2 != 0) {
                if (B & two) goto failed;
                x += two;
                y += two;
            }
        }
        if (!(x + y == A && (x ^ y) == B)) {
            goto failed;
        }
        cout << x << " " << y << endl;
        continue;
    failed:;
        puts("-1");
    }
    
    return 0;
}