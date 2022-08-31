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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

Int Abs(Int x) { return (x < 0) ? -x : x; }
Int myFloor(Int a, Int b) {
    return (a < 0) ? (a / b - 1) : (a / b);
}
Int solve(Int a, Int p, Int q) {
//cout<<a<<" "<<p<<" "<<q<<endl;
    return Abs(myFloor(p, a) - myFloor(q, a));
}

Int A, B, X0, Y0, X1, Y1;

int main() {
    
    
    for (; cin >> A >> B >> X0 >> Y0 >> X1 >> Y1; ) {
        Int e = solve(A * 2, X0 + Y0, X1 + Y1);
        Int f = solve(B * 2, X0 - Y0, X1 - Y1);
        cout << max(e, f) << endl;
    }
    
    return 0;
}