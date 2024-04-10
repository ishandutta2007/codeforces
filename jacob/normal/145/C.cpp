#include <cstdio>
#include <map>
#include <vector>
using namespace std;

bool isLucky(int p) {
    if (p == 0)
        return false;
    while (p != 0) {
        if (p%10 != 4 && p%10 != 7)
            return false;
        p /= 10;
    }
    return true;
}

typedef long long i64;
const i64 MOD = i64(1e9 + 7);

i64 fastPow(i64 a, i64 p) {
    i64 res = 1;
    while (p) {
        if (p % 2 == 1)
            res = res * a % MOD;
        a = a*a % MOD;
        p /= 2;
    }
    return res;
}

int main(void) {
    map<int, int> occ;
    int n, k;
    scanf("%d%d", &n, &k);
    int notLucky = 0;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (isLucky(t)) {
            ++occ[t];
        } else
            ++notLucky;
    }
    int m = (int)occ.size();
    vector< vector<int> > v(m+1, vector<int>(m+1));
    v[0][0] = 1;
    int cnt = 0;
    for (map<int, int>::const_iterator it = occ.begin(); it != occ.end(); ++it) {
        ++cnt;
        for (int i = 0; i < m + 1; i++) {
            v[cnt][i] = v[cnt - 1][i];
            if (i != 0) {
                v[cnt][i] += (v[cnt-1][i-1] * i64(it->second)) % MOD;
                if (v[cnt][i] >= MOD)
                    v[cnt][i] -= MOD;
            }
        }
    }
    vector<i64> factorials(notLucky + 1);
    factorials[0] = 1;
    for (int i = 0; i < notLucky; i++) {
        factorials[i+1] = factorials[i] * (i+1) % MOD;
    }
    vector<i64> invFact(notLucky + 1);
    for (int i = 0; i <= notLucky; i++) {
        invFact[i] = fastPow(factorials[i], MOD - 2);
    }
    i64 res = 0;
    for (int i = 0; i <= m; i++) {
        int k2 = k - i;
        if (k2 < 0)
            continue;
        if (k2 > notLucky)
            continue;
        res += (v[m][i] * factorials[notLucky]) % MOD * invFact[k2] % MOD * invFact[notLucky - k2] % MOD;
        res %= MOD;
    }
    printf("%d\n", (int)res);
    return 0;
}