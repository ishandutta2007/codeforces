#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <bitset>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

const int64 mod = 1000000007LL;

int main() {
    int n;
    cin >> n;
    int64 d[2];
    d[0] = d[1] = 1;
    for (int i = 0; i < n; ++i) {
        int p = i % 2;
        int q = (i + 1) % 2;
        d[q] = (d[q] + d[p]) % mod;
    }
    int64 res = d[0] + d[1];
    res -= 2;
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << "\n";
    return 0;
}