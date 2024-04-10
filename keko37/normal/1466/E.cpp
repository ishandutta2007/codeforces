#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 500005;
const int MOD = 1000000007;

int t, n;
llint x[MAXN], br[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int calc (llint val) {
    int res_and = 0, res_or = 0;
    for (int i = 0; i < 60; i++) {
        if (val & (1LL << i)) {
            res_and = add(res_and, mul(br[i], (1LL << i) % MOD));
            res_or = add(res_or, mul(n, (1LL << i) % MOD));
        } else {
            res_or = add(res_or, mul(br[i], (1LL << i) % MOD));
        }
    }
    return mul(res_and, res_or);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(br, 0, sizeof br);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            for (int j = 0; j < 60; j++) {
                if (x[i] & (1LL << j)) br[j]++;
            }
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            sol = add(sol, calc(x[i]));
        }
        cout << sol << '\n';
    }
    return 0;
}