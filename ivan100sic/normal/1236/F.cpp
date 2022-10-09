// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

template<int m>
struct modint {
    unsigned x;

    modint() : x(0) {}
    modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

    modint operator+ (const modint& b) const {
        auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator- (const modint& b) const {
        auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
    }

    modint operator* (const modint& b) const {
        auto t = *this; t.x = ll(t.x) * b.x % m; return t;
    }

    modint operator/ (const modint& b) const {
        return *this * b.inv();
    }

    template<class T> modint operator^ (T n) const {
        modint t;
        if (n == 0) return t.x = 1, t;
        if (n == 1) return t.x = x, t;
        t = *this ^ (n >> 1); t *= t;
        return n & 1 ? *this * t : t;
    }

    modint& operator+= (const modint& b) { return *this = *this + b; }
    modint& operator-= (const modint& b) { return *this = *this - b; }
    modint& operator*= (const modint& b) { return *this = *this * b; }
    modint& operator/= (const modint& b) { return *this = *this / b; }
    modint& operator++ () { if (++x == m) x = 0; return *this; }
    modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
    modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
    modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
    bool operator== (const modint& other) const { return x == other.x; }
    bool operator!= (const modint& other) const { return x != other.x; }
    int operator() () const { return x; }
    template<class T> modint operator^= (T n) { return *this = *this ^ n; }
    modint inv() const { return *this ^ (m-2); }
};

const int mod = 1000 * 1000 * 1000 + 7;
typedef modint<mod> mint;

const mint half = mint(1) / 2;
mint pw2[1000005], pwh[1000005];
int n, m;
vector<int> e[500005];

vector<vector<int>> bp;
vector<int> paths_rooted[500005];
int bpath[500005], bord[500005], par[500005];

char vis[500005];
void dfs(int x, int p) {
    par[x] = p;
    vis[x] = 1;
    for (int y : e[x]) {
        if (y == p) continue;
        if (!vis[y]) {
            dfs(y, x);
        } else if (vis[y] == 1) {
            // b-e
            int bid = ssize(bp);
            bp.emplace_back();
            for (int t=x, i=0; t!=y; t=par[t], i++) {
                bpath[t] = bid;
                bord[t] = i;
                bp.back().push_back(t);
            }
            bp.back().push_back(y);
            for (int t : bp.back()) {
                paths_rooted[t].push_back(bid);
            }
        }
    }
    vis[x] = 2;
}

mint e_self[500005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    pwh[0] = pw2[0] = 1;
    pwh[1] = mint(1) / 2;
    pw2[1] = 2;

    for (int x : ra(2, 2*n+1)) pw2[x] = pw2[x-1] * 2;
    for (int x : ra(2, 2*n+1)) pwh[x] = pwh[x-1] * half;

    fill(bpath+1, bpath+n+1, -1);
    dfs(1, -1);

    mint ev = half * n;
    mint ee = pwh[2] * m; // m / 4
    mint ec = 0;
    for (auto& path : bp) {
        ec += pwh[size(path)];
    }
    mint ex = ev - ee + ec;

    // V x V
    mint evv = pwh[2] * n * (n+1);

    // E x E
    mint eee = 0;
    {
        // same edge
        eee += pwh[2] * m;

        // adjacent but different edges
        mint cnt = 0;
        for (int x : ra(1, n+1)) {
            cnt += mint(ssize(e[x])) * (ssize(e[x]) - 1);
        }
        eee += cnt * pwh[3]; // 1/8

        // unrelated edges
        cnt = mint(m)*m - m - cnt;

        eee += cnt * pwh[4]; // 1/16
    }

    // C x C
    mint ecc = 0;
    {
        mint sum = 0;
        // same cycles
        for (auto& path : bp) {
            mint term = pwh[size(path)];
            ecc += term;
            sum += term;
        }

        // adjacent but different cycles
        // these can only be found at cycle roots
        for (int x : ra(1, n+1)) {
            mint sum = 0; // sum of 2^-len

            for (int id : paths_rooted[x]) {
                int len = ssize(bp[id]);
                ecc += sum * pwh[len] * 4; // x2 root node, x2 counting twice
                sum += pwh[len];
            }
        }

        // unrelated cycles, first add all pairs
        mint unrel = sum * sum;

        // remove same-pairs
        for (auto& path : bp) {
            unrel -= pwh[2 * size(path)];
        }

        // remove adj but different pairs
        for (int x : ra(1, n+1)) {
            mint sum = 0; // sum of 2^-len
            for (int id : paths_rooted[x]) {
                int len = ssize(bp[id]);
                unrel -= sum * pwh[len] * 2; // x2 counting twice
                sum += pwh[len];
            }
        }

        // finally add unrelated to sol
        ecc += unrel;
    }

    // V x E
    mint eve = 0;
    {
        // unrelated vertex-edge
        eve += pwh[3] * m * (n-2);

        // related vertex-edge
        eve += pwh[2] * m * 2;
    }

    // E x C
    mint eec = 0;
    for (auto& path : bp) {
        int len = size(path);
        // let's classify edges
        int inside = len;

        int touching = 0;
        for (int x : path) {
            touching += ssize(e[x]);
        }
        touching -= 2 * len;

        int unrelated = m - inside - touching;

        eec += pwh[len] * inside;
        eec += pwh[len+1] * touching;
        eec += pwh[len+2] * unrelated;
    }

    // V x C
    mint evc = 0;
    for (auto& path : bp) {
        int len = size(path);
        // let's classify vertices
        int inside = len;
        int unrelated = n - inside;

        evc += pwh[len] * inside;
        evc += pwh[len+1] * unrelated;
    }

    mint exx = evv + eee + ecc - eve*2 - eec*2 + evc*2;

    cerr << "E(X) = " << (ex * pw2[n])() << "/ " << (1<<n) << '\n';
    int quot = 1 << (n+n);
    cerr << "E(V^2)   = " << (evv  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(E^2)   = " << (eee  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(C^2)   = " << (ecc  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(VE)   = " << (eve  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(EC)   = " << (eec  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(VC)   = " << (evc  * pw2[n+n])()   << "/ " << quot << '\n';
    cerr << "E(X^2) = " << (exx * pw2[n+n])() << "/ " << quot << '\n';

    cout << (exx - ex*ex)() << '\n';    
}