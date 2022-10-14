#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const llint INF = 1000000000000000000LL;

llint n, k, sol;

int len (llint x) {
    int res = 0;
    while (x > 0) x /= 2, res++;
    return res;
}

llint f (llint x) {
    if (x == 0) return n;
    if (x > n) return 0;
    llint res = 0;
    if (x % 2 == 0) res += f(x + 1);
    int ost = len(n) - len(x);
    res += (1LL << ost) - 1;
    if (x == (n >> ost)) res += n % (1LL << ost) + 1;
    if (x < (n >> ost)) res += (1LL << ost);
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < 2; i++) {
        llint lo = 0, hi = n;
        while (lo < hi) {
            llint mid = (lo + hi + 1) / 2;
            if (f(2 * mid + i) >= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        sol = max(sol, 2 * lo + i);
    }
    cout << sol;
    return 0;
}