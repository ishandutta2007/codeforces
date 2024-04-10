#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, sol;
int pot[MAXN], pref[MAXN], suf[MAXN];
string s;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++) {
        pot[i] = add(mul(pot[i - 1], 10), 1);
    }
    for (int i = 0; i < n; i++) {
        int d = s[i] - '0';
        if (i == 0) {
            pref[i] = d;
        } else {
            pref[i] = add(mul(pref[i - 1], 10), d);
        }
        if (i != n-1) sol = add(sol, mul(pref[i], pot[n-1 - i]));
    }
    int t = 1;
    for (int i = n-1; i >= 0; i--) {
        int d = s[i] - '0';
        suf[i] = add(suf[i + 1], mul(d, t));
        t = mul(t, 10);
        sol = add(sol, mul(suf[i], i));
    }
    cout << sol;
    return 0;
}