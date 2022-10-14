#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const int LOG = 18;
const int MOD = 1000000007;

int n, B = 31337;
int pot[MAXN], dub[MAXN], sol[MAXN];
int par[MAXN][LOG], h[MAXN][LOG];
string s;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void precompute () {
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = mul(pot[i - 1], B);
    }
}

void add_node (int x) {
    dub[x] = 1 + dub[par[x][0]];
    h[x][0] = s[x];
    for (int i = 1; i < LOG; i++) {
        par[x][i] = par[par[x][i - 1]][i - 1];
        h[x][i] = add(mul(h[x][i - 1], pot[1 << (i - 1)]), h[par[x][i - 1]][i - 1]);
    }
}

bool cmp (int a, int b) {
    int len = 0, ha = 0, hb = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if ((1 << i) <= min(dub[a], dub[b])) {
            int novi_ha = add(mul(ha, pot[1 << i]), h[a][i]);
            int novi_hb = add(mul(hb, pot[1 << i]), h[b][i]);
            if (novi_ha == novi_hb) {
                a = par[a][i];
                b = par[b][i];
                ha = novi_ha;
                hb = novi_hb;
            }
        }
    }
    if (a == n) return 1;
    if (b == n) return 0;
    return s[a] <= s[b];
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[x][pot];
        pot++;
        k /= 2;
    }
    return x;
}

void ispis (int x, int br) {
    for (int i = 0; i < br; i++) {
        cout << s[x];
        x = par[x][0];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    precompute();
    sol[n] = n;
    for (int i = n-1; i >= 0; i--) {
        par[i][0] = sol[i + 1];
        add_node(i);
        if (i != n-1 && s[i] == s[i + 1]) {
            int b = sol[i + 2];
            if (cmp(i, b)) sol[i] = i; else sol[i] = b;
        } else {
            sol[i] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int x = sol[i];
        cout << dub[x] << " ";
        if (dub[x] <= 10) {
            ispis(x, dub[x]);
        } else {
            ispis(x, 5);
            cout << "...";
            ispis(kth(x, dub[x] - 2), 2);
        }
        cout << '\n';
    }
    return 0;
}