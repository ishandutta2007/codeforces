#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 300005;
const int MOD = 998244353;

int n;
int a[MAXN], sum[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int pot (int x, int e) {
    if (e == 0) return 1;
    int t = pot(x, e / 2);
    t = mul(t, t);
    if (e & 1) t = mul(t, x);
    return t;
}

int calc (int k) {
    int res = 0, cnt = 1;
    for (int i = n - k; i > 0; i -= k) {
        int lo = max(1, i - k + 1);
        res = add(res, mul(cnt, sub(sum[i], sum[lo - 1])));
        cnt++;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = add(a[i], sum[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << mul(calc(i), pot(n, MOD - 2)) << " ";
    }
    return 0;
}