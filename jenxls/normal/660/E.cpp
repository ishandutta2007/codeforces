#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int mod = 1e9 + 7;
int n, m, ans;

inline int pw (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ans = (ans + 1ll * pw(m, i + 1) * pw(2 * m - 1, n - i - 1)) % mod;
    }

    ans = (ans + pw(m, n)) % mod;

    cout << ans << '\n';
}