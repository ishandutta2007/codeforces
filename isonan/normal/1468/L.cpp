#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

// orz Sooke
const ll base[10] = {0, 2, 3, 5, 7, 23, 61, 6011, 97, 101};

inline ll power(ll x, ll y, ll p) { ll res = 1; for (; y; y >>= 1, x = (__int128) x * x % p) { if (y & 1) { res = (__int128) res * x % p; } } return res; }

bool millerRabin(ll n) {
    for (int i = 1; i <= 9; i++) { if (n % base[i] == 0) { return n == base[i]; } }
    ll m = n - 1; int s = 0;
    while (!(m & 1)) { m >>= 1; s++; }
    for (int i = 1, j; i <= 9; i++) {
        ll x = power(base[i], m, n);
        if (x == 1 || x == n - 1) { continue; }
        for (j = 1; j <= s; j++) {
            x = (__int128) x * x % n;
            if (x == n - 1) { break; }
        }
        if (j > s) { return false; }
    }
    return true;
}

const int N = 1005;

map <ll, int> id;
ll a[N], pri[N];
vector <int> pos[N];
int used[N], cnt[N], now[N], qaq[N];
int n, k, tot, ans1;

int main() {
    read(n); read(k);
    if (k == 1) {
        print(0, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 59; j++) {
            ll l = 1, r = a[i], ans = a[i];
            while (l <= r) {
                ll mid = (l + r) >> 1;
                __int128 sum = 1;
                for (int k = 1; k <= j; k++) {
                    sum = min((__int128)a[i], sum * mid);
                }
                if (sum >= a[i]) ans = mid, r = mid - 1;
                else l = mid + 1;
            }
            __int128 sum = 1;
            int cando = 1;
            for (int k = 1; k <= j; k++) {
                sum *= ans;
                if (sum > a[i]) {
                    cando = 0;
                    break;
                }
            }
            if (!cando || !millerRabin(ans)) continue;
            if (!id.count(ans)) id[ans] = ++tot, pri[tot] = ans;
            qaq[i] = id[ans];
            used[i] = 1; ++cnt[id[ans]]; pos[id[ans]].push_back(i);
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (cnt[i] >= 2) {
            ans1 += cnt[i];
        }
    }
    if (k <= ans1) {
        int odd = 0;
        for (int i = 1; i <= tot; i++) {
            if (cnt[i] >= 3) {
                odd = i;
                break;
            }
        }
        vector <int> ans;
        if (k % 2 == 1 && odd) {
            k -= 3;
            now[odd] = 3;
            ans.push_back(pos[odd][0]);
            ans.push_back(pos[odd][1]);
            ans.push_back(pos[odd][2]);
        }
        if (k % 2 == 0) {
            for (int i = 1; i <= tot && k; i++) {
                if (cnt[i] >= 2 && !now[i]) {
                    k -= 2; now[i] = 2;
                    ans.push_back(pos[i][0]);
                    ans.push_back(pos[i][1]);
                }
            }
            for (int i = 1; i <= tot && k; i++) {
                if (cnt[i] >= 2) {
                    while (now[i] < cnt[i] && k) {
                        ans.push_back(pos[i][now[i]]);
                        ++now[i]; --k;
                    }
                }
            }
            for (int i = 0; i < (int)ans.size(); i++) print(a[ans[i]], i == (int)ans.size() - 1 ? '\n' : ' ');
        } else {
            int cando = 0;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    int ct = 0;
                    ll tmp = a[i];
                    for (int j = 1; j <= tot; j++) {
                        if (cnt[j] >= 2 && a[i] % pri[j] == 0) {
                            ++ct;
                            while (tmp % pri[j] == 0) tmp /= pri[j];
                        }
                    }
                    if (tmp == 1 && ct * 2 + 1 <= k) {
                        cando = 1;
                        ans.push_back(i);
                        for (int j = 1; j <= tot; j++) {
                            if (a[i] % pri[j] == 0) {
                                now[j] = 2;
                                ans.push_back(pos[j][0]);
                                ans.push_back(pos[j][1]);
                            }
                        }
                        k -= ct * 2 + 1;
                        break;
                    }
                }
            }
            if (!cando) print(0, '\n');
            else {
                for (int i = 1; i <= tot && k; i++) {
                    if (cnt[i] >= 2 && !now[i]) {
                        ans.push_back(pos[i][0]);
                        ans.push_back(pos[i][1]);
                        now[i] = 2; k -= 2;
                    }
                }
                for (int i = 1; i <= tot && k; i++) {
                    if (cnt[i] >= 2) {
                        while (now[i] < cnt[i] && k) {
                            ans.push_back(pos[i][now[i]]);
                            ++now[i]; --k;
                        }
                    }
                }
                for (int i = 0; i < (int)ans.size(); i++) print(a[ans[i]], i == (int)ans.size() - 1 ? '\n' : ' ');
            }
        }
        return 0;
    }
    vector <int> ans;
    k -= ans1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            if (!k) continue;
            ll tmp = a[i];
            for (int j = 1; j <= tot; j++) {
                if (cnt[j] >= 2 && tmp % pri[j] == 0) {
                    while (tmp % pri[j] == 0) tmp /= pri[j];
                }
            }
            if (tmp == 1) {
                ans.push_back(i);
                --k;
            }
        } else if (cnt[qaq[i]] >= 2) ans.push_back(i);
    }
    if (k) {
        print(0, '\n');
        return 0;
    }
    for (int i = 0; i < (int)ans.size(); i++) print(a[ans[i]], i == (int)ans.size() - 1 ? '\n' : ' ');
    return 0;
}