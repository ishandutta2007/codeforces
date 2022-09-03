#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

struct DoubleHash : public pair<unsigned, unsigned> {
    using ull = unsigned long long;
    static pair<unsigned, unsigned> MODs;
    DoubleHash(pair<unsigned, unsigned> x) : pair(x) {}
    DoubleHash(unsigned x, unsigned y) : pair(x, y) {}
    DoubleHash(unsigned x) : DoubleHash(x, x) {}
    DoubleHash() : DoubleHash(0) {}
    static inline DoubleHash mod_subtract(pair<unsigned, unsigned> x) {
        if (x.first >= MODs.first) x.first -= MODs.first;
        if (x.second >= MODs.second) x.second -= MODs.second;
        return x;
    }
    DoubleHash operator+(const DoubleHash &x) const { return mod_subtract({this->first + x.first, this->second + x.second}); }
    DoubleHash operator+(unsigned x) const { return mod_subtract({this->first + x, this->second + x}); }
    DoubleHash operator-(const DoubleHash &x) const { return mod_subtract({this->first + MODs.first - x.first, this->second + MODs.second - x.second}); }
    DoubleHash operator*(const DoubleHash &x) const { return {unsigned(ull(this->first) * x.first % MODs.first), unsigned(ull(this->second) * x.second % MODs.second)}; }
    DoubleHash operator*(unsigned x) const { return {unsigned(ull(this->first) * x % MODs.first), unsigned(ull(this->second) * x % MODs.second)}; }
    static DoubleHash gen_b(bool force_update = false) {
        static DoubleHash b{0, 0};
        if (b == DoubleHash{0, 0} or force_update) {
            mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
            uniform_int_distribution<unsigned> d(1 << 16, 1 << 29);
            b = {d(mt), d(mt)};
        }
        return b;
    }
};
pair<unsigned, unsigned> DoubleHash::MODs{1000000007, 998244353};

// Rolling Hash (Rabin-Karp), 1dim
template <typename V = DoubleHash> struct rolling_hash {
    int N;
    V B;
    vector<V> hash;  // hash[i] = s[0] * B^(i - 1) + ... + s[i - 1]
    vector<V> power; // power[i] = B^i
    rolling_hash(const string &s = "", V b = V::gen_b()) : B(b) {
        N = s.length();
        hash.resize(N + 1), power.resize(N + 1, 1);
        for (int i = 0; i < N; i++) {
            power[i + 1] = power[i] * B;
            hash[i + 1] = hash[i] * B + s[i];
        }
    }
    void addchar(const char &c) {
        V hnew = hash[N] * B + c, pnew = power[N] * B;
        N++, hash.emplace_back(hnew), power.emplace_back(pnew);
    }
    V get(int l, int r) const { // s[l] * B^(r - l - 1) + ... + s[r - 1]
        return hash[r] - hash[l] * power[r - l];
    }
};

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, Q;
    string S, T;
    cin >> N >> Q >> S >> T;

    vector<int> Ssz{int(S.length())};
    REP(i, T.size()) {
        if (S.length() <= 1e6) {
            S = S + T[i] + S;
            Ssz.emplace_back(S.length());
        } else break;
    }

    constexpr int MOD = 1000000007;
    array<vector<long long>, 26> dcnt;
    REP(d, 26) dcnt[d].resize(N + 1);
    REP(i, N) {
        REP(d, 26) dcnt[d][i + 1] = dcnt[d][i] * 2 % MOD;
        dcnt[T[i] - 'a'][i + 1] += 1;
    }

    rolling_hash RH(S);

    auto solve = [&](int k, string Q) -> long long {
        if (Q.length() > S.length()) return 0;
        const int d = lower_bound(Ssz.begin(), Ssz.end(), Q.length()) - Ssz.begin();
        if (d > k) return 0;
        auto p2 = [&](string s) { return accumulate(s.begin(), s.end(), 1LL, [&](long long cur, char c) { return cur * cur % MOD * (c - '0' + 1) % MOD; }); }(std::bitset<20>(k - d).to_string());

        rolling_hash QH(Q);
        long long ret = 0;
        for (int i = 0; i + Q.length() <= Ssz[d]; i++) if (QH.get(0, Q.length()) == RH.get(i, i + Q.length())) ret += p2;

        REP(q, Q.length()) {
            if ((QH.get(0, q) == RH.get(S.length() - q, S.length())) and QH.get(q + 1, Q.length()) == RH.get(0, Q.length() - 1 - q)) {
                ret += dcnt[Q[q] - 'a'][k] - dcnt[Q[q] - 'a'][d] * p2 % MOD + MOD;
            }
        }
        return ret % MOD;
    };

    while (Q--) {
        int k;
        string s;
        cin >> k >> s;
        cout << solve(k, s) << '\n';
    }
}