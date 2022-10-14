#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;
const llint INF = 1000000000000000000LL;

llint n, sum, sol = INF;
llint a[MAXN], p[MAXN];
vector <llint> v;

void precompute () {
    for (llint i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            while (sum % i == 0) sum /= i;
            v.push_back(i);
        }
    }
    if (sum > 1) v.push_back(sum);
}

llint check (llint x) {
    llint res = 0;
    for (int i = 1; i <= n; i++) {
        res += min(p[i] % x, x - p[i] % x);
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        sum += a[i];
    }
    if (sum == 1) {
        cout << -1;
        return 0;
    }
    precompute();
    for (auto x : v) sol = min(sol, check(x));
    cout << sol;
    return 0;
}