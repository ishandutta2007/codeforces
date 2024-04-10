#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int MOD = 998244353;

int n, sol;
int pot[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    pot[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pot[i] = mul(pot[i - 1], 2);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (j < n) {
                sol = add(sol, pot[n - j - 1]);
            } else {
                sol = add(sol, 1);
            }
        }
    }
    cout << sol;
    return 0;
}