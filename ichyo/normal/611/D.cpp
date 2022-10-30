// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

namespace SA{
    const int MAX_N = 5005; // 

    int n, k;
    int rank[MAX_N + 1];
    int tmp[MAX_N + 1];

    // (rank[i], rank[i + k])  (rank[j], rank[j + k]) 
    bool comp(int i, int j){
        if(rank[i] != rank[j]) return rank[i] < rank[j];
        int ri = i + k <= n ? rank[i + k] : -1;
        int rj = j + k <= n ? rank[j + k] : -1;
        return ri < rj;
    }

    vector<int> buildSA(const string& s){
        n = s.size();
        vector<int> sa(n + 1);

        // 1, 
        for(int i = 0; i <= n; i++){
            sa[i] = i;
            rank[i] = i < n ? s[i] : -1;
        }

        // k2k
        for(k = 1; k <= n; k *= 2){
            sort(sa.begin(), sa.end(), comp);

            tmp[sa[0]] = 0;
            for(int i = 1; i <= n; i++){
                tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            for(int i = 0; i <= n; i++){
                rank[i] = tmp[i];
            }
        }

        return sa;
    }

    vector<int> buildLCP(string s, const vector<int>& sa){
        n = s.size();
        vector<int> lcp(n);

        for(int i = 0; i <= n; i++) rank[sa[i]] = i;

        int h = 0;
        lcp[0] = 0;
        for(int i = 0; i < n; i++){
            // iLCP
            int j = sa[rank[i] - 1];

            // h1
            if(h > 0) h--;
            for(; j + h < n && i + h < n; h++){
                if(s[j + h] != s[i + h]) break;
            }

            lcp[rank[i] - 1] = h;
        }

        return lcp;
    }
}

template<typename T, typename Comp=less<T>>
class SparseTable{
    private:
        Comp comp;
        int N, K;
        vector<T> value;
        vector<vector<int>> idx;

        inline int log2(int x) {
            return 31 - __builtin_clz(x);
        }

    public:
        SparseTable() {}
        SparseTable(const vector<T>& v) : value(v) {
            N = v.size();
            K = log2(N) + 1;

            idx.resize(K);
            idx[0].resize(N);
            REP(i, N) idx[0][i] = i;

            for(int log = 0; log+1 < K; log++) {
                const int L = N+1 - (1<<(log+1));
                idx[log+1].resize(L);
                for(int i = 0; i < L; i++) {
                    const int p = idx[log][i];
                    const int q = idx[log][i+(1<<log)];
                    idx[log+1][i] = (comp(v[p], v[q]) ? p : q);
                }
            }
        }

        // return index of minimum/maximum value in v[b], ..., v[e-1]
        int query_idx(int b, int e) {
            const int log = log2(e-b);
            const int p = idx[log][b];
            const int q = idx[log][e-(1<<log)];
            return (comp(value[p], value[q]) ? p : q);
        }

        // return minimum/maximum value in v[b], ..., v[e-1]
        int query(int b, int e) {
            return value[query_idx(b, e)];
        }
};

int n;
string s;
vector<int> sa, lcp;
SparseTable<int> sp;

int compare(int x, int y) {
    // [x, y) [y, y+y-x)
    int a = SA::rank[x];
    int b = SA::rank[y];
    int h = sp.query(min(a, b), max(a, b));
    if(h >= y - x) return 0;
    return (b > a ? -1 : +1);
}

// ModInt (ref. anta) {{{
template<int MOD>
struct ModInt{
    static const int Mod = MOD;
    unsigned val;
    ModInt():val(0){}
    ModInt(unsigned x):val(x%MOD){}
    ModInt(signed x) {
        int y = x % MOD;
        if(y < 0) y += MOD;
        val = y;
    }
    ModInt(signed long long x) {
        int y = x % MOD;
        if(y < 0) y += MOD;
        val = y;
    }

    ModInt &operator+=(ModInt rhs) {
        val += rhs.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    ModInt &operator-=(ModInt rhs) {
        val += MOD - rhs.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    ModInt &operator*=(ModInt rhs) {
        val = (unsigned long long)val * rhs.val % MOD;
        return *this;
    }
    ModInt &operator/=(ModInt rhs) {
        return *this *= rhs.inv();
    }

    ModInt inv() const {
        signed a = val, b = MOD, u = 1, v = 0;
        while(b) {
            signed t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if(u < 0) u += MOD;
        ModInt res;
        res.val = u;
        return res;
    }

    ModInt operator+(ModInt rhs) const {
        return ModInt(*this) += rhs;
    }
    ModInt operator-(ModInt rhs) const {
        return ModInt(*this) -= rhs;
    }
    ModInt operator*(ModInt rhs) const {
        return ModInt(*this) *= rhs;
    }
    ModInt operator/(ModInt rhs) const {
        return ModInt(*this) /= rhs;
    }

    // compare
    bool operator==(ModInt rhs) const {
        return val == rhs.val;
    }
    bool operator!=(ModInt rhs) const {
        return val != rhs.val;
    }
    bool operator< (ModInt rhs) const {
        return val <  rhs.val;
    }
    bool operator<=(ModInt rhs) const {
        return val <= rhs.val;
    }
    bool operator> (ModInt rhs) const {
        return val >  rhs.val;
    }
    bool operator>=(ModInt rhs) const {
        return val >= rhs.val;
    }
};
template<int MOD>
ostream& operator << (ostream& os, const ModInt<MOD> m) {
    return os << m.val;
}
template<int MOD, typename T>
ModInt<MOD> pow(ModInt<MOD> a, T b) {
    if(b == 0) {
        return 1;
    } else {
        auto w = pow(a*a, b/2);
        if(b&1) w *= a;
        return w;
    }
}
// }}}
typedef ModInt<1000000007> mint;
mint dp[5001][5001];

int main(){
    iostream_init();
    while(cin >> n) {
        cin >> s;

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        sa = SA::buildSA(s);
        lcp = SA::buildLCP(s, sa);
        sp = SparseTable<int>(lcp);

        memset(dp, 0, sizeof(dp));
        mint ans = 1;
        dp[0][1] = 1;
        for(int k = 0; k < n; k++) {
            mint val = 0;
            for(int i = k+1; i < n; i++) {
                val += dp[k][i];
                if(s[i] == '0') continue;

                const int l = i - k;
                const int bi = i - l;
                const int ul = (compare(bi, i) < 0 ? l : l+1);

                if(i + ul <= n) {
                    // cout << i << " " << l << " " << ul << " " << val << endl;
                    ans += val;
                }

                const int ni = i + ul;
                if(ni >= n) continue;

                const int nk = k + l;
                dp[nk][ni] += val;
            }
        }
        cout << ans.val << endl;
    }
    return 0;
}