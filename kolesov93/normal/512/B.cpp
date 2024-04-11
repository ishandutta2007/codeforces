#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acos(-1.);

int gcd(int a, int b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

const int N = 333;
int a[N];
int cost[N];

vector<int> getPrimes(int x) {
    vector<int> result;
    for (int i = 2; i * i <= x; ++i) {
        if (!(x % i)) {
            result.push_back(i);
            while (!(x % i)) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        if (result.size() == 0 || result.back() != x) result.push_back(x);
    }
    return result;
}

int getMask(int x, vector<int>& primes) {
    int res = 0;
    for (int i = 0; i < primes.size(); ++i) {
        if (!(x % primes[i])) res += (1 << i);
    }
    return res;
}
int getValue(int x, vector<int>& primes) {
    int res = 1;
    for (int i = 0; i < primes.size(); ++i) {
        if (x & (1 << i)) res *= primes[i];
    }
    return res;
}

const int M = 11;
int f[N][1 << M];
int value[1 << M];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];
    
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        vector<int> b = getPrimes(x);
        int m = b.size();
        int lim = 1 << m;
        for (int msk = 0; msk < lim; ++msk) value[msk] = getValue(msk, b);

        memset(f, 63, sizeof(f));
        f[i][lim - 1] = cost[i];
        for (int j = i; j < n; ++j)
            for (int msk = 0; msk < lim; ++msk) {
                int nmsk = getMask(gcd(a[j + 1], value[msk]), b); 
                f[j + 1][nmsk] = min(f[j + 1][nmsk], f[j][msk] + cost[j + 1]);
                f[j + 1][msk] = min(f[j + 1][msk], f[j][msk]);
            }
        ans = min(ans, f[n][0]); 
    }
    if (ans < 1e9) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}