#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 250005;

int n, m, sol;
int f[MAXN];

int mul (int a, int b) {return (llint) a * b % m;}
int add (int a, int b) {a += b; if (a >= m) return a - m; return a;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = mul(f[i - 1], i);
    }
    for (int i = 1; i <= n; i++) {
        int val = mul(mul(n - i + 1, n - i + 1), mul(f[i], f[n - i]));
        sol = add(sol, val);
    }
    cout << sol;
    return 0;
}