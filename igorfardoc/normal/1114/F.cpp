#include<bits/stdc++.h>
#define maxn 400000
#define maxa 300
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
const int mod1 = mod - 1;

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) res = ((ll)res * a) % mod;
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

int lp2[maxa + 1];
vi pr;
int n, q;

int t[maxn * 4 + 7], lp[maxn * 4 + 7];
ll t1[maxn * 4 + 7], lp1[maxn * 4 + 7];

ll getval(int a) {
    ll here = 0;
    for(int i = 0; i < pr.size(); i++) {
        if(a % pr[i] == 0) {
            here ^= (1ll << i);
        }
    }
    return here;
}

void precalc() {
    for(int i = 2; i <= maxa; i++) {
        if(lp2[i] == 0) {
            lp2[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp2[i] && i * pr[j] <= maxa; j++) {
            lp2[i * pr[j]] = pr[j];
        }
    }
    for(int i = 0; i < maxn * 4 + 7; i++) {
        lp[i] = t[i] = 1;
    }
}

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l > r1 || l1 > r) return;
    if(l1 <= l && r <= r1) {
        int here = bin_pow(val, r - l + 1);
        t[now] = ((ll)t[now] * here) % mod;
        lp[now] = ((ll)lp[now] * val) % mod;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    t[now] = (ll)t[now * 2] * t[now * 2 + 1] % mod * bin_pow(lp[now], r - l + 1) % mod;
}

int get(int now, int l, int r, int l1, int r1, int val = 1) {
    if(l1 > r || l > r1) return 1;
    if(l1 <= l && r <= r1) return (ll)t[now] * bin_pow(val, r - l + 1) % mod;
    val = (ll)val * lp[now] % mod;
    int mid = (l + r) / 2;
    return (ll)get(now * 2, l, mid, l1, r1, val) * get(now * 2 + 1, mid + 1, r, l1, r1, val) % mod;
}

void update1(int now, int l, int r, int l1, int r1, ll val) {
    if(l1 > r || l > r1) return;
    if(l1 <= l && r <= r1) {
        t1[now] |= val;
        lp1[now] |= val;
        return;
    }
    int mid = (l + r) / 2;
    update1(now * 2, l, mid, l1, r1, val);
    update1(now * 2 + 1, mid + 1, r, l1, r1, val);
    t1[now] = t1[now * 2] | t1[now * 2 + 1] | lp1[now];
}

ll get1(int now, int l, int r, int l1, int r1, ll val = 0) {
    if(l1 > r || l > r1) return 0;
    if(l1 <= l && r <= r1) return t1[now] | val;
    val |= lp1[now];
    int mid = (l + r) / 2;
    return get1(now * 2, l, mid, l1, r1, val) | get1(now * 2 + 1, mid + 1, r, l1, r1, val);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    precalc();
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        update(1, 0, n - 1, i, i, val);
        ll here = getval(val);
        update1(1, 0, n - 1, i, i, here);
    }
    for(int o = 0; o < q; o++) {
        string s;
        cin >> s;
        if(s[0] == 'M') {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            --r;
            update(1, 0, n - 1, l, r, x);
            ll here = getval(x);
            update1(1, 0, n - 1, l, r, here);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int ans = get(1, 0, n - 1, l, r);
            ll here = get1(1, 0, n - 1, l, r);
            for(int i = 0; i < pr.size(); i++) {
                if((here >> i) & 1) {
                    ans = (ll)ans * (pr[i] - 1) % mod;
                    ans = (ll)ans * obr(pr[i]) % mod;
                }
            }
            cout << ans << '\n';
        }
    }


}