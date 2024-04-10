#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MOD = 998244353;
const int MAXN = 300005;

int n, k, sol;
int lef[MAXN], rig[MAXN];
int fact[MAXN], inv[MAXN], in[MAXN * 2], out[MAXN * 2];
vector <int> v;

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

int nck (int nn, int kk) {
    //cout << "nck " << nn << " " << kk << endl;
    if (nn < 0) return 0;
    if (!(0 <= kk && kk <= nn)) return 0;
    return mul(fact[nn], mul(inv[kk], inv[nn - kk]));
}

void precompute () {
    fact[0] = 1; inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pot(fact[i], MOD - 2);
    }
}

void sweep () {
    int curr = 0;
    for (int i = 1; i < MAXN * 2; i++) {
        curr -= out[i];
        for (int j = 0; j < in[i]; j++) {
            sol = add(sol, nck(curr, k - 1));
            curr++;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> lef[i] >> rig[i];
        v.push_back(lef[i]);
        v.push_back(rig[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
        lef[i] = lower_bound(v.begin(), v.end(), lef[i]) - v.begin() + 1;
        rig[i] = lower_bound(v.begin(), v.end(), rig[i]) - v.begin() + 1;
        in[lef[i]]++; out[rig[i] + 1]++;
    }
    sweep();
    cout << sol;
    return 0;
}