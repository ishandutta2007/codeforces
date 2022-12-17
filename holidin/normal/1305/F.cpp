#include <bits/stdc++.h>
#pragma GCC optimize 03
#define int long long
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 22;

bool use[N];
vector <int> prime;

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

mt19937 rnd(10000);

void solve() {
    int i, j, n, a, b;
    cin >> n;
    vector <int> v(n);
    int sum = 0;
    for (i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (i = 2; i < N; ++i)
    if (!use[i]) {
        prime.push_back(i);
        for (j = 2; i * j < N; ++j)
            use[i * j] = 1;
    }
    int ans = n;
    int cnt = 0;
    for (i = 0; i < v.size(); ++i)
    if (i  == 0 || v[i] != v[i - 1]) {
        ++cnt;
        if (cnt > 10000)
            break;
        int x = v[i];
        for (j = 0; j < prime.size() && prime[j] * prime[j] <= x; ++j) {
            while (x % prime[j] == 0 && x > 0) {
                x /= prime[j];
            }
        }
        if (clock() >= 2 * CLOCKS_PER_SEC)
            break;
        if (x > 1)
            prime.push_back(x);
    }
    for (i = 0; i < 10000; ++i) {
        int x1 = v[rnd() % n];
        int x2 = v[rnd() % n];
        if (rand() % 2)
            x1 = max((int) 1, x1 - (int) rnd() % 10);
        else
            x1 += rnd() % 10;
        if (rand() % 2)
            x2 = max((int) 1, x2 - (int) rnd() % 10);
        else
            x2 += rnd() % 10;
        int f = nod(x2, x1);
        if (f > 1)
            prime.push_back(f);
    }
    sort(prime.begin(), prime.end());
    prime.resize(unique(prime.begin(), prime.end()) - prime.begin());
    for (auto p : prime) {
        int tsum = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] >= p)
                tsum += min(v[i] % p, p - (v[i] % p));
            else
                tsum += p - (v[i] % p);
            if (tsum >= ans)
                break;
        }
        if (tsum < ans) {
            ans = tsum;
        }
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}