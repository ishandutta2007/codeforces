#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 400005;
const int MOD = 1000000007;

int t, n;
int a[MAXN], b[MAXN], p[MAXN], bio[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void dfs (int x) {
    if (bio[x]) return;
    bio[x] = 1;
    dfs(p[x]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            p[a[i]] = b[i];
            bio[i] = 0;
        }
        int sol = 1;
        for (int i = 1; i <= n; i++) {
            if (!bio[i]) {
                sol = mul(sol, 2);
                dfs(i);
            }
        }
        cout << sol << '\n';
    }
    return 0;
}