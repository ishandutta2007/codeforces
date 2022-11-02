#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 gcd(int64 x, int64 y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int64 mulMod(int64 x, int64 y, int64 p) {
    if (y == 0) return 0;
    if (x < 1000111000111000111LL / y) return x * y % p;
    int64 mid = mulMod((x + x) % p, y >> 1LL, p);
    if (y & 1)
        return (mid + x) % p;
    else
        return mid;
}
int64 powMod(int64 x, int64 k, int64 m) {
    if (k == 0) return 1;
    if ((k & 1))
        return mulMod(x, powMod(x, k - 1, m), m);
    else
        return powMod(mulMod(x, x, m), k / 2, m);
}
bool suspect(int64 a, int64 s, int64 d, int64 n) {
    int64 x = powMod(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return true;
        x = mulMod(x, x, n);
    }
    return false;
}

bool isPrime(int64 n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    int64 test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, -1};
    int64 d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}

int64 pollard_rho(int64 n, int64 seed) {
    int64 x, y;
    x = y = rand() % (n - 1) + 1;
    int head = 1, tail = 2;
    while (true) {
        x = mulMod(x, x, n);
        x = (x + seed) % n;
        if (x == y) return n;
        int64 d = gcd(max(x - y, y - x), n);
        if (1 < d && d < n) return d;
        if (++head == tail) y = x, tail <<= 1;
    }
}

void factorize(int64 n, vector<int64> &divisor) {
    if (n == 1) return;
    if (isPrime(n))
        divisor.push_back(n);
    else {
        int64 d = n;
        while (d >= n) d = pollard_rho(n, rand() % (n - 1) + 1);
        factorize(n / d, divisor);
        factorize(d, divisor);
    }
}

int64 n, x, y, arr[200009];

vector<int64> vec;
vector<int64> lc, gc;

int64 dp[(1 << 17) + 2], dp2[(1 << 17) + 2];
int64 dp3[(1 << 17) + 2], dp4[(1 << 17) + 2];

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);
    if (y % x) return cout << 0 << endl, 0;
    int one = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        if (arr[i] == 1) ++one;
    }
    if (y == 1) return cout << n * one << endl, 0;
    factorize(y, vec);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int m = vec.size();
    int64 temp, cnt;
    for (int i = 0; i < m; ++i) {
        temp = y, cnt = 0;
        while (temp % vec[i] == 0) ++cnt, temp /= vec[i];
        lc.push_back(cnt);
        temp = x, cnt = 0;
        while (temp % vec[i] == 0) ++cnt, temp /= vec[i];
        gc.push_back(cnt);
    }
    for (int i = 1; i <= n; ++i) {
        if (y % arr[i]) continue;
        int mask = 0;
        for (int j = 0; j < m; ++j) {
            temp = arr[i], cnt = 0;
            while (temp % vec[j] == 0) ++cnt, temp /= vec[j];
            if (cnt != lc[j] && lc[j] != gc[j]) mask |= (1 << j);
        }
        ++dp[mask];
    }
    for (int i = 0; i < (1 << m); ++i) {
        dp2[i] = dp[i];
        int temp = i;
        while (temp > 0) temp = ((temp - 1) & i), dp2[i] += dp[temp];
    }
    int64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] % x) continue;
        int mask = 0;
        for (int j = 0; j < m; ++j) {
            temp = arr[i], cnt = 0;
            while (temp % vec[j] == 0) ++cnt, temp /= vec[j];
            if (cnt == gc[j]) mask |= (1 << j);
        }
        ans += dp2[mask];
    }
    cout << ans << endl;
    return 0;
}