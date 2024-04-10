//  Codeforces Beta Round #86

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

Int TEN[110];

int changeTo0(Int x) {
    ostringstream os;
    os << x;
    string s = os.str();
    return s.size() - count(s.begin(), s.end(), '0');
}

Int A, B;

Int solve(Int a, int k) {
    Int ret = 0;
    
    if (k <= 0) {
        return a;
    }
    
    if (k <= 15) {
        Int tmp;
        tmp = a / TEN[k - 1];
        ret += tmp;
    }
    
    return ret;
}
Int solve(Int a, Int b, int k) {
    Int ret = 0;
    
    if (k <= 0) {
        return a * B + b;
    }
    
    //  only B
    if (k <= 15) {
        Int tmp;
        tmp = (B - 1) / TEN[k - 1];
        ret += tmp * a;
        tmp = b / TEN[k - 1];
        ret += tmp;
    }
    
    //  with A
    int dk = changeTo0(B - 1);
    ret += solve(a, k - dk);
    
//cout<<"solve "<<a<<" "<<b<<" "<<k<<" : "<<ret<<endl;
    return ret;
}

int main() {
    int K;
    Int a0, b0;
    Int a1, b1;
    
    int i;
    TEN[0] = 1;
    for (i = 1; i < 30; ++i) {
        TEN[i] = TEN[i - 1] * 10;
    }
    
    for (; cin >> A >> B >> K >> a0 >> b0 >> a1 >> b1; ) {
        Int ans = 0;
        if (a0 * B + b0 <= a1 * B + b1) {
            ans += solve(a1, b1, K);
            ans -= solve(a0, b0, K);
        } else {
            ans += solve(A - 1, B - 1, K);
            ans -= solve(a0, b0, K);
            ans += solve(a1, b1, K);
            if (changeTo0(A - 1) + changeTo0(B - 1) >= K) {
                ans += 1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}