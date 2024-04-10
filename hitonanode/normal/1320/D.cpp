#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int N;
string T;
int Q;

pair<string, vector<int>> solt(string T)
{
    int N = T.length();
    vector<int> v{-1};
    string ret;
    int suc = 0;
    REP(i, N)
    {
        if (T[i] == '0') {
            if (suc % 2) ret += '1';
            suc = 0;
            ret += '0';
            v.push_back(i);
        }
        else suc++;
    }
    if (suc % 2) ret += '1';
    v.push_back(N);
    return make_pair(ret, v);
}

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

// Rolling Hash (Rabin-Karp), 1dim
template<typename V>
struct rolling_hash
{
    V B;
    vector<V> hash; // hash[i] = s[0] * B^(i - 1) + ... + s[i - 1]
    vector<V> power; // power[i] = B^i
    rolling_hash() {}
    rolling_hash(const string &s, V b) : B(b)
    {
        int N = s.length();
        hash.resize(N + 1), power.resize(N + 1, 1);
        for (int i = 0; i < N; i++)
        {
            power[i + 1] = power[i] * B;
            hash[i + 1] = hash[i] * B + s[i];
        }
    }
    V get_hash(int l, int r) // s[l] * B^(r - l - 1) + ... + s[r - 1]
    {
        return hash[r] - hash[l] * power[r - l];
    }
};

using lint = long long;
using plint = pair<lint, lint>;
struct DoubleHash : public plint
{
    static plint MODs;
    DoubleHash(plint x) : plint(x) {}
    DoubleHash(lint x, lint y) : plint(x, y) {}
    DoubleHash(lint x) : DoubleHash(x, x) {}
    DoubleHash() : DoubleHash(0) {}
    static inline DoubleHash mod_subtract(plint x)
    {
        if (x.first >= MODs.first) x.first -= MODs.first;
        if (x.second >= MODs.second) x.second -= MODs.second;
        return x;
    }
    DoubleHash operator+(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first + x.first, this->second + x.second));
    }
    DoubleHash operator+(lint x) const
    {
        return mod_subtract(plint(this->first + x, this->second + x));
    }
    DoubleHash operator-(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first - x.first + MODs.first, this->second - x.second + MODs.second));
    }
    DoubleHash operator*(const DoubleHash &x) const
    {
        return make_pair(this->first * x.first % MODs.first, this->second * x.second % MODs.second);
    }
    DoubleHash operator*(lint x) const
    {
        return make_pair(this->first * x % MODs.first, this->second * x % MODs.second);
    }
};
plint DoubleHash::MODs = plint(1000000007, 998244353);
rolling_hash<DoubleHash> rh;
vector<int> nxtz, prvz;

vector<int> zaatsu; // i -> zaatsu zero
pair<DoubleHash, pint> solve(int l, int r)
{
    int lz = nxtz[l];
    int rz = prvz[r - 1];
    if (lz > rz) {
        return make_pair(DoubleHash(-1, -1), pint(r - l - 10000000, -1));
    }
    pint rp = make_pair((lz - l) % 2, (r - rz) % 2);
    return make_pair(rh.get_hash(zaatsu[lz], zaatsu[rz]), rp);
}

int main()
{
    cin >> N >> T;
    N = T.length();

    nxtz.resize(N);
    prvz.resize(N);
    string Ttrunc;
    vector<int> zeropos;
    tie(Ttrunc, zeropos) = solt(T);
    {
        int t = 0;
        REP(i, N) {
            while (zeropos[t] < i) t++;
            nxtz[i] = zeropos[t];
        }
        t = zeropos.size() - 1;
        IREP(i, N) {
            while (zeropos[t] > i) t--;
            prvz[i] = zeropos[t];
        }
    }
    zaatsu.resize(N);
    {
        int j = 0;
        REP(i, N) if (T[i] == '0') {
            while (Ttrunc[j] != '0') j++;
            zaatsu[i] = j;
            j++;
        }
    }
    // dbg(Ttrunc);
    // dbg(nxtz);
    // dbg(prvz);
    // dbg(zaatsu);

    DoubleHash b(rnd(1, 100000), rnd(1, 1000000));
    rh = rolling_hash<DoubleHash>(Ttrunc, b);

    vector<int> ret;
    cin >> Q;
    while (Q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--, l2--;
        auto h1 = solve(l1, l1 + len);
        auto h2 = solve(l2, l2 + len);
        ret.push_back(h1 == h2);
    }

    for (auto v : ret) {
        if (v) puts("Yes");
        else puts("No");
    }
}