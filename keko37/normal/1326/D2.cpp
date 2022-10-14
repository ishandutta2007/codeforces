#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int MOD = 1000000007;
const int B = 32465;

int tt, n, len;
string s, t;
int pref[MAXN], suf[MAXN], pot[MAXN];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int get_hash_pref (int a, int b) {
    if (a == 0) return pref[b];
    return sub(pref[b], mul(pot[b - a + 1], pref[a - 1]));
}

int get_hash_suf (int a, int b) {
    if (b == len - 1) return suf[a];
    return sub(suf[a], mul(pot[b - a + 1], suf[b + 1]));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> s;
        n = s.size();
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n - 1 - i]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            cout << s << '\n';
            continue;
        }
        int lef = ind, rig = n - 1 - ind;
        t = s.substr(lef, rig - lef + 1);
        len = t.size();
        pot[0] = 1;
        for (int i = 1; i <= len; i++) {
            pot[i] = mul(pot[i - 1], B);
        }
        for (int i = 0; i < len; i++) {
            pref[i] = add(mul((i == 0 ? 0 : pref[i - 1]), B), t[i]);
        }
        for (int i = len - 1; i >= 0; i--) {
            suf[i] = add(mul((i == len-1 ? 0 : suf[i + 1]), B), t[i]);
        }
        int sola = -1, solb = -1;
        for (int i = 0; i < len; i++) {
            //cout << "bla " << get_hash_pref(0, i) << " " << get_hash_suf(0, i) << endl;
            if (get_hash_pref(0, i) == get_hash_suf(0, i)) sola = 0, solb = i;
            if (get_hash_pref(len - 1 - i, len - 1) == get_hash_suf(len - 1 - i, len - 1)) sola = len - 1 - i, solb = len - 1;
        }
        for (int i = 0; i < ind; i++) cout << s[i];
        for (int i = sola; i <= solb; i++) cout << t[i];
        for (int i = ind - 1; i >= 0; i--) cout << s[i];
        cout << '\n';
    }
    return 0;
}