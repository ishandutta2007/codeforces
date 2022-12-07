#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N = 1000500;
int F[N];
vector<int> primes;

const int M = 21111;
ll f[2][M];

ll doit(ll x) {
    if (x <= 2) return -1;
    x -= 1;

    for (ll prime : primes) {
        if (prime * prime > x) break;
        if (!(x % prime)) {
            while (!(x % prime)) x /= prime;
            if (x == 1) return prime;
            return -1;
        }
    }
    return x;
}

int main() {
    for (int i = 2; i < N; ++i) {
        if (!F[i]) {
            primes.push_back(i);
            for (int j = i + i; j < N; j += i)
                F[j] = 1;
        }
    }

    ll n;
    cin >> n;

    vector<ll> d;
    for (ll i = 1; i * i <= n; ++i) {
        if (!(n % i)) {
            d.push_back(i);
            if (i * i != n) d.push_back(n / i);
        }
    }
    sort(begin(d), end(d));
    map<ll, int> where;
    for (size_t i = 0; i < d.size(); ++i)
        where[d[i]] = i;


    set<ll> cool;
    for (ll x : d) {
        ll res = doit(x);
        if (res != -1) {
            cool.insert(res);
        }
    }
    vector<ll> nums(cool.begin(), cool.end());

    f[0][0] = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
        int w = i & 1;
        int ww = 1 - w;
        memset(f[ww], 0, sizeof(f[ww]));
        for (size_t j = 0; j < d.size(); ++j) {
            if (!f[w][j]) continue;

            ll value = d[j];
            ll prime = nums[i];
            ll add = prime;

            f[ww][j] += f[w][j];
            while (double(value) * (add + 1) <= 2 * n) {
                ll nvalue = value * (add + 1);
                auto it = where.find(nvalue);
                if (it != where.end()) {
                    int pos = it->second;
                    f[ww][pos] += f[w][j];
                }
                if (double(add) * prime > 2 * n) break;
                add *= prime;
            }
        }
    }

    cout << f[nums.size() & 1][int(d.size()) - 1] << endl;

    return 0;
}