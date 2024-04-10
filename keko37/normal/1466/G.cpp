#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int MOD = 1000000007;
const int B = 31337;

int n, q;
int s_siz, r_siz;
int pot[MAXN], pot2[MAXN], sh[MAXN], rh[MAXN], sum[100005][26];
int rig_len[MAXN], rig_ok[MAXN], lef_len[MAXN], lef_ok[MAXN];
string s, t, r;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void precompute () {
    pot2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pot2[i] = mul(pot2[i - 1], 2);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0)
            for (int j = 0; j < 26; j++)
                sum[i][j] = mul(sum[i - 1][j], 2);
        sum[i][t[i] - 'a'] = add(sum[i][t[i] - 'a'], 1);
    }
}

void precompute_hash_s () {
    pot[0] = 1;
    for (int i = 1; i < MAXN; i++) pot[i] = pot[i - 1] * B;
    for (int i = 0; i < s_siz; i++)
        sh[i] = (i == 0 ? 0 : sh[i - 1]) * B + s[i];
}

void precompute_hash_r () {
    for (int i = 0; i < r_siz; i++)
        rh[i] = (i == 0 ? 0 : rh[i - 1]) * B + r[i];
}

int get_hash_s (int a, int b) {if (a == 0) return sh[b]; return sh[b] - sh[a - 1] * pot[b - a + 1];}
int get_hash_r (int a, int b) {if (a == 0) return rh[b]; return rh[b] - rh[a - 1] * pot[b - a + 1];}

void calc_rig () {
    for (int i = r_siz - 1; i >= 0; i--) {
        if (s_siz >= r_siz - i) {
            int d = r_siz - i;
            if (get_hash_r(i, r_siz - 1) != get_hash_s(0, d - 1)) {
                rig_ok[i] = 0;
                continue;
            }
            rig_ok[i] = 1; rig_len[i] = 0;
            continue;
        }
        rig_ok[i] = 1;
        int len = s_siz, br = 0, curr = get_hash_s(0, s_siz - 1);
        while (2 * len + 1 <= r_siz - i) {
            if (br >= n || r[i + len] != t[br]) rig_ok[i] = 0;
            br++;
            curr = curr * pot[len + 1] + r[i + len] * pot[len] + curr;
            len = 2 * len + 1;
        }
        if (get_hash_r(i, i + len - 1) != curr) rig_ok[i] = 0;
        if (i + len < r_siz) {
            if (i + len + 1 < r_siz) rig_ok[i] &= rig_ok[i + len + 1];
            if (br >= n || r[i + len] != t[br]) rig_ok[i] = 0;
            br++;
        }
        if (rig_ok[i]) rig_len[i] = br;
    }
}

void calc_lef () {
    for (int i = 0; i < r_siz; i++) {
        if (s_siz >= i + 1) {
            int d = i + 1;
            if (get_hash_r(0, i) != get_hash_s(s_siz - d, s_siz - 1)) {
                lef_ok[i] = 0;
                continue;
            }
            lef_ok[i] = 1; lef_len[i] = 0;
            continue;
        }
        lef_ok[i] = 1;
        int len = s_siz, br = 0, curr = get_hash_s(0, s_siz - 1);
        while (2 * len + 1 <= i + 1) {
            if (br >= n || r[i - len] != t[br]) lef_ok[i] = 0;
            br++;
            curr = curr * pot[len + 1] + r[i - len] * pot[len] + curr;
            len = 2 * len + 1;
        }
        if (get_hash_r(i - len + 1, i) != curr) lef_ok[i] = 0;
        if (i - len >= 0) {
            if (i - len - 1 >= 0) lef_ok[i] &= lef_ok[i - len - 1];
            if (br >= n || r[i - len] != t[br]) lef_ok[i] = 0;
            br++;
        }
        if (lef_ok[i]) lef_len[i] = br;
    }
}

int calc (int ind) {
    int res = 0;
    if (r_siz <= s_siz) {
        int cnt = 0;
        for (int i = 0; r_siz <= s_siz - i; i++) {
            if (get_hash_s(i, i + r_siz - 1) == get_hash_r(0, r_siz - 1)) cnt++;
        }
        res = add(res, mul(cnt, pot2[ind]));
    }
    ind--;
    for (int i = 0; i < r_siz; i++) {
        if ((i == 0 || lef_ok[i - 1]) && (i == r_siz - 1 || rig_ok[i + 1])) {
            int len = 0;
            if (i != 0) len = max(len, lef_len[i - 1]);
            if (i != r_siz - 1) len = max(len, rig_len[i + 1]);
            int c = r[i] - 'a';
            if (len <= ind) {
                res = add(res, sum[ind][c]);
                if (len > 0) res = sub(res, mul(sum[len - 1][c], pot2[ind - len + 1]));
            }
        }
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s >> t;
    precompute();
    s_siz = s.size();
    precompute_hash_s();
    for (int i = 0; i < q; i++) {
        int ind;
        cin >> ind >> r;
        r_siz = r.size();
        precompute_hash_r();
        calc_lef();
        calc_rig();
        cout << calc(ind) << '\n';
    }
    return 0;
}