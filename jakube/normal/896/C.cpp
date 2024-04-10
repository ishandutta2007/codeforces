#include <bits/stdc++.h>
using namespace std;

int MOD;

long long power(long long base, int e)
{
    long long result = 1;
    base %= MOD;
    while (e) {
        if (e & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return result;
}

long long seed;

long long rnd()
{
    auto old = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return old;
}

struct S {
    int l, r;
    long long val;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, vmax;
    cin >> n >> m >> seed >> vmax;

    vector<S> v;
    for (int i = 0; i < n; i++) {
        v.push_back({i, i, (rnd() % vmax) + 1});
    }

    for (int i = 0; i < m; i++) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n);
        int r = (rnd() % n);
        if (l > r)
            swap(l, r);
        int x, y;
        if (op == 3)
            x = (rnd() % (r - l + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;

        if (op == 4)
            y = (rnd() % vmax) + 1;

        if (op == 1) {
            vector<S> w;
            for (auto s : v) {
                if (s.r < l || s.l > r) {
                    w.push_back(s);
                } else if (s.l < l && s.r > r) {
                    auto xx = s;
                    auto yy = s;
                    auto zz = s;
                    xx.r = l - 1;
                    yy.l = l;
                    yy.r = r;
                    yy.val += x;
                    zz.l = r + 1;
                    w.push_back(xx);
                    w.push_back(yy);
                    w.push_back(zz);
                } else if (s.l < l) {
                    auto z = s;
                    z.r = l - 1;
                    s.l = l;
                    s.val += x;
                    w.push_back(z);
                    w.push_back(s);
                } else if (s.r > r) {
                    auto z = s;
                    s.r = r;
                    s.val += x;
                    z.l = r + 1;
                    w.push_back(s);
                    w.push_back(z);
                } else {
                    s.val += x;
                    w.push_back(s);
                }
            }
            w.swap(v);
        } else if (op == 2) {
            vector<S> w;
            bool b = false;
            for (auto s : v) {
                if (s.r < l || s.l > r) {
                    w.push_back(s);
                } else if (s.l < l && s.r > r) {
                    auto xx = s;
                    auto yy = s;
                    auto zz = s;
                    xx.r = l - 1;
                    yy.l = l;
                    yy.r = r;
                    yy.val = x;
                    zz.l = r + 1;
                    w.push_back(xx);
                    w.push_back(yy);
                    w.push_back(zz);
                } else if (s.l < l) {
                    auto z = s;
                    z.r = l - 1;
                    w.push_back(z);
                    w.push_back({l, r, x});
                    b = true;
                } else if (s.r > r) {
                    auto z = s;
                    z.l = r + 1;
                    if (!b)
                    w.push_back({l, r, x});
                    w.push_back(z);
                } else {
                    if (!b) {
                        w.push_back({l, r, x});
                        b = true;
                    }
                }
            }
            w.swap(v);
        } else if (op == 3) {
            vector<pair<long long, int>> w;
            for (auto s : v) {
                if (s.r >= l && s.l <= r)
                    w.push_back({s.val, min(r, s.r) - max(l, s.l) + 1});
            }
            sort(w.begin(), w.end());
            x--;
            for (auto p : w) {
                if (p.second > x) {
                    cout << p.first << '\n';
                    break;
                }
                x -= p.second;
            }
        } else if (op == 4) {
            long long total = 0;
            MOD = y;
            for (auto s : v) {
                if (s.r >= l && s.l <= r)
                    total += ((min(r, s.r) - max(l, s.l) + 1) * power(s.val, x)) % MOD;
            }
            cout << total % MOD << '\n';
        }
    }
}