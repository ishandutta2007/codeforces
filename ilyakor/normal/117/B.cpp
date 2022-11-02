/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main() {
    int64 a, b;
    int mod;
    cin >> a >> b >> mod;
    int64 x = 1;
    for (int i = 0; i < 9; ++i)
        x = (x * 10LL) % mod;
    int64 l = 1, r = mod - b - 1;
    int64 opt = -1;
    
    int t = 0;
    for (int cur = 1; cur <= a && cur <= mod + 2; ++cur) {
        t += (int) x;
        t %= mod;
//        cerr << l << " " << r << " " << cur << " " << t << "\n";
        if (t < l || t > r) continue;
        opt = cur;
        break;
    }
    if (opt == -1) printf("2\n");
    else printf("1 %09d\n", (int) opt);
    return 0;
}