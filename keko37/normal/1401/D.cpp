#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const int MOD = 1000000007;

int t, n, m;
llint p[MAXN], siz[MAXN];
vector <llint> v[MAXN], r;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void dfs (int x, int rod) {
    siz[x] = 1;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
        siz[x] += siz[sus];
    }
    if (rod) r.push_back(siz[x] * (n - siz[x]));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) v[i].clear();
        r.clear();
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1, 0);
        sort(r.begin(), r.end());
        for (int i = 0; i < n-1; i++) r[i] %= MOD;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p, p + m);
        llint sol = 0, curr = m - 1;
        for (int i = n - 2; i >= 0; i--) {
            int br = 1;
            while (curr > i) {
                br = mul(br, p[curr]);
                curr--;
            }
            if (curr >= 0) br = mul(br, p[curr]);
            curr--;
            sol = add(sol, mul(r[i], br));
        }
        cout << sol << '\n';
    }
    return 0;
}