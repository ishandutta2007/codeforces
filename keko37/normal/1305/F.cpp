#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, sol = MAXN;
llint a[MAXN];

llint cost (llint p) {
    llint res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < p) {
            res += p - a[i];
        } else {
            llint ost = a[i] % p;
            res += min(ost, p - ost);
        }
        if (res > n) return MAXN;
    }
    return res;
}

void factor (llint val) {
    if (val <= 0) return;
    for (llint i = 2; i * i <= val; i++) {
        if (val % i != 0) continue;
        while (val % i == 0) val /= i;
        sol = min(sol, cost(i));
    }
    if (val > 1) sol = min(sol, cost(val));
}

void check (int ind) {
    for (int d = -1; d <= 1; d++) {
        llint val = a[ind] + d;
        factor(val);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 30; i++) {
        check(uniform_int_distribution <int> (0, n)(rng));
    }
    cout << sol;
    return 0;
}