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
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }



int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    
    char buf[110];
    int a;
    
    for (; ~scanf("%s%d", buf, &a); ) {
        int s = 0;
        if (!strcmp(buf, "back")) s ^= 1;
        if (a != 1) s ^= 1;
        puts(s ? "R" : "L");
    }
    
    return 0;
}