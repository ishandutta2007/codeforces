#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


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
struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r)
    {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

DoubleHash b(rnd(2, 1000000), rnd(2, 1000000));

lint ret;
vector<int> A;

map<DoubleHash, int> solve(const vector<int> &v)
{
    vector<int> vec{0};
    vector<DoubleHash> d{0};
    map<DoubleHash, int> ret;

    for (auto x : v)
    {
        if (vec.back() == x)
        {
            vec.pop_back();
            d.pop_back();
        }
        else
        {
            vec.push_back(x);
            DoubleHash y = d.back() * b + x;
            d.push_back(y);
        }
        ret[d.back()]++;
    }
    return ret;
}

void divconq(int l, int r)
{
    if (r - l < 2) return;
    if (r - l == 2)
    {
        if (A[l] == A[l + 1]) ret++;
        return;
    }
    int c = (l + r) / 2;
    divconq(l, c);
    divconq(c, r);

    vector<int> vr(r - c);
    vector<int> vl(c - l);
    REP(i, r - c) vr[i] = A[c + i];
    REP(i, c - l) vl[i] = A[c - 1 - i];
    map<DoubleHash, int> ml = solve(vl), mr = solve(vr);
    for (auto p : ml)
    {
        ret += (lint)p.second * mr[p.first];
    }
}

lint solve()
{
    int N;
    cin >> N;
    A.resize(N);
    cin >> A;
    ret = 0;
    divconq(0, N);
    return ret;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        printf("%lld\n", solve());
    }
}