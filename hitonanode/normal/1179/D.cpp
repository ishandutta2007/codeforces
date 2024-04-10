/*
Convex Hull Trick
- y = ax + b /
- y = c(x - a)^2 + b (a, b)
Verify:
<https://codeforces.com/contest/1179/problem/D>
<https://codeforces.com/contest/1137/submission/59447595>
*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

struct mpint
{
    static const int D = 9, DD = 1000000000;
    int sign;
    vector<int> data;
    mpint() : sign(1), data(0) {}
    mpint(const string &S) { str2num(S); }
    mpint(lint v) { *this = v; }

    void str2num(const string &S) {
        int buf = 0, ten = 1;
        sign = 1, data.clear();
        IREP(i, S.size())
        {
            if (S[i] == '-') sign *= -1;
            else if (S[i] - '0' >= 0 and S[i] - '0' <= 10)
            {
                buf += (S[i] - '0') * ten;
                ten *= 10;
                if (ten == DD) data.push_back(buf), buf = 0, ten = 1;
            }
        }
        if (buf) data.push_back(buf);
        pop_zero();
    }
    void pop_zero() { while (!data.empty() and !data.back()) data.pop_back(); if (data.empty()) sign = 1; }
    mpint abs() const { mpint ret = *this; ret.sign = 1; return ret; }

    void operator=(const mpint &x) { sign = x.sign, data = x.data; }
    void operator=(lint x) { sign = (x < 0 ? -1 : 1), x = std::abs(x); while(x) data.push_back(x % DD), x /= DD; }
    mpint operator-() const { mpint ret = *this; if (ret.data.size()) ret.sign *= -1; return ret; }
    mpint operator+(const mpint &x) const {
        if (sign == x.sign) {
            mpint ret = *this;
            int now = 0, moveup = 0;
            while (now < (int)x.data.size() or moveup)
            {
                if ((int)ret.data.size() == now) ret.data.push_back(0);
                ret.data[now] += moveup + (now < (int)x.data.size() ? x.data[now] : 0);
                moveup = (ret.data[now] >= DD);
                if (moveup) ret.data[now] -= DD;
                now++;
            }
            return ret;
        }
        else return *this - (-x);
    }
    mpint operator-(const mpint &x) const {
        if (sign == x.sign)
        {
            if (abs() >= x.abs()) {
                mpint ret = *this;
                IREP(i, x.data.size()) {
                    ret.data[i] -= x.data[i];
                    if (ret.data[i] < 0) ret.data[i + 1]--, ret.data[i] += DD;
                }
                ret.pop_zero();
                return ret;
            }
            else return -(x - *this);
        }
        else return *this + (-x);
    }
    bool operator<(const mpint &r) const {
        if (sign != r.sign) return sign < r.sign;
        if (data.size() != r.data.size()) return data.size() * sign < r.data.size() * r.sign;
        IREP(i, data.size()) if (data[i] != r.data[i]) return data[i] * sign < r.data[i] * r.sign;
        return false;
    }
    bool operator>(const mpint &r) const { return r < *this; }
    bool operator<=(const mpint &r) const { return !(r < *this); }
    bool operator>=(const mpint &r) const { return !(*this < r); }
    bool operator==(const mpint &r) const { return sign == r.sign and data == r.data; }
    bool operator!=(const mpint &r) const { return !(*this == r); }
    void operator*=(int x) {
        if (x < 0) sign *= -1, x *= -1;
        int now = 0;
        lint moveup = 0;
        while (now < (int)data.size() or moveup) {
            if (now == (int)data.size()) data.push_back(0);
            moveup = (lint)data[now] * x + moveup;
            data[now] = moveup % DD, moveup /= DD;
            now++;
        }
        pop_zero();
    }
    mpint operator*(int x) const { mpint ret = *this; ret *= x; return ret; }
    void operator/=(int x) {
        if (x < 0) sign *= -1, x *= -1;
        lint buff = 0;
        IREP(i, data.size()) {
            buff = data[i] + buff * DD;
            data[i] = buff / x;
            buff %= x;
        }
        pop_zero();
    }
    mpint operator/(int x) const { mpint ret = *this; ret /= x; return ret; }

    static pair<mpint, mpint> div(const mpint &a1, const mpint &b1) {
        int n = DD / (b1.data.back() + 1);
        mpint a = a1.abs() * n, b = b1.abs() * n, q, r;
        q.data.resize(a.data.size());
        IREP(i, a.data.size())
        {
            r = r * DD + a.data[i];
            int s1 = r.data.size() <= b.data.size() ? 0 : r.data[b.data.size()];
            int s2 = r.data.size() <= b.data.size() - 1 ? 0 : r.data[b.data.size() - 1];
            int d = ((lint)DD * s1 + s2) / b.data.back();
            r -= b * d;
            while (r < 0) r += b, --d;
            q.data[i] = d;
        }
        q.sign = a1.sign * b1.sign, r.sign = a1.sign;
        q.pop_zero(), r.pop_zero();
        return make_pair(q, r / n);
    }

    static mpint shiftd(const mpint &x, int d) {
        mpint ret;
        ret.sign = x.sign, ret.data.assign(x.data.size() + d, 0);
        REP(i, x.data.size()) ret.data[i + d] = x.data[i];
        ret.pop_zero();
        return ret;
    }
    mpint operator*(const mpint &x) const {
        mpint ret;
        REP(i, data.size()) ret += shiftd(x * data[i], i);
        ret.sign *= sign;
        ret.pop_zero();
        return ret;
    }
    mpint operator/(const mpint &x) const { return div(*this, x).first; }
    mpint operator%(const mpint &x) const { return div(*this, x).second; }
    void operator+=(const mpint &x) { *this = *this + x; }
    void operator-=(const mpint &x) { *this = *this - x; }
    void operator*=(const mpint &x) { *this = *this * x; }
    void operator/=(const mpint &x) { *this = *this / x; }
    void operator%=(const mpint &x) { *this = *this % x; }

    friend istream& operator>>(istream &is, mpint &x) {
        string s;
        is >> s;
        x.str2num(s);
        return is;
    }
    friend ostream& operator<<(ostream &os, const mpint &x) {
        if (x.sign == -1) os << '-';
        os << (x.data.empty() ? 0 : x.data.back());
        IREP(i, x.data.size() - 1) os << setw(D) << setfill('0') << x.data[i];
        return os;
    }
};

/*
Convex Hull Trick
Implementation Idea: <https://github.com/satanic0258/Cpp_snippet/blob/master/src/technique/ConvexHullTrick.cpp>
*/
using T_CHT = lint;
struct ConvexHullTrick
{
    static const T_CHT T_MIN = numeric_limits<T_CHT>::lowest() + 1;
    struct Line
    {
        T_CHT a, b; // y = ax + b
        mutable pair<T_CHT, T_CHT> rp; // (numerator, denominator) `x` coordinate of the crossing point with next line
        Line(T_CHT a, T_CHT b) : a(a), b(b), rp(T_MIN, T_MIN) {}
        static pair<T_CHT, T_CHT> cross(const Line &ll, const Line &lr)
        {
            return make_pair(ll.b - lr.b, lr.a - ll.a); // `ll.a < lr.a` is assumed implicitly
        }
        bool operator<(const Line &r) const
        {
            if (b == T_MIN)
            {
                if (r.rp.first == T_MIN) return true;
                else return a * r.rp.second < r.rp.first;
            }
            else if (r.b == T_MIN)
            {
                if (rp.first == T_MIN) return false;
                else return !(r.a * rp.second < rp.first);
            }
            else return a < r.a;
        }
    };
    struct Lines : multiset<Line>
    {
        bool flg_min; // true iff for minimization
        inline bool isNeedless(iterator itr)
        {
            if (size() == 1) return false;
            auto nxt = next(itr);
            if (itr == begin()) return itr->a == nxt->a and itr->b <= nxt->b;
            else
            {
                auto prv = prev(itr);
                if (nxt == end()) return itr->a == prv->a and itr->b <= prv->b;
                // Prevent overflow
                else return mpint(prv->b - itr->b) * (nxt->a - itr->a) >= mpint(itr->b - nxt->b) * (itr->a - prv->a);
            }
        }
        void add_line(T_CHT a, T_CHT b)
        {
            if (flg_min) a = -a, b = -b;
            auto itr = insert({a, b});
            if (isNeedless(itr)) erase(itr);
            else
            {
                while (next(itr) != end() and isNeedless(next(itr)))
                {
                    erase(next(itr));
                }
                while (itr != begin() and isNeedless(prev(itr)))
                {
                    erase(prev(itr));
                }
                if (next(itr) != end())
                {
                    itr->rp = Line::cross(*itr, *next(itr));
                }
                if (itr != begin())
                {
                    prev(itr)->rp = Line::cross(*prev(itr), *itr);
                }
            }
        }
        Lines(bool is_minimizer): flg_min(is_minimizer) {}
        pair<T_CHT, T_CHT> get(T_CHT x)
        {
            auto itr = lower_bound({x, T_MIN});
            T_CHT retval = T_MIN, reta = T_MIN;
            if (itr != end())
            {
                retval = itr->a * x + itr->b;
                reta = itr->a;
            }
            if (itr != begin())
            {
                T_CHT tmp = prev(itr)->a * x + prev(itr)->b;
                if (tmp >= retval)
                {
                    retval = tmp;
                    reta = max(reta, prev(itr)->a);
                }
            }
            return make_pair(flg_min ? -retval : retval, flg_min ? -reta : reta);
        }
    };
    Lines lines;
    ConvexHullTrick(bool is_minimizer) : lines(is_minimizer) {}
    void add_line(T_CHT a, T_CHT b) { lines.add_line(a, b); } // Add y = ax + b
    pair<T_CHT, T_CHT> get(T_CHT x) { return lines.get(x); }
    void add_convex_parabola(T_CHT c, T_CHT a, T_CHT b) { add_line(-2 * c * a, c * a * a + b); } // Add y = c(x - a)^2 + b
    T_CHT parabola_lower_bound(T_CHT c, T_CHT x) { return lines.get(x).first + c * x * x; }
};
const T_CHT ConvexHullTrick::T_MIN;


lint N;
vector<vector<int>> edges;
lint ret = 1e12;
plint dfs(int now, int prv)
{
    lint stsz = 1;
    vector<lint> sz, dp;
    for (auto nxt : edges[now]) if (nxt != prv)
    {
        plint pa = dfs(nxt, now);
        sz.push_back(pa.first);
        dp.push_back(pa.second);
        stsz += pa.first;
    }

    ConvexHullTrick cht(true);
    REP(i, sz.size())
    {
        if (i) mmin(ret, cht.parabola_lower_bound(1, sz[i]) + dp[i]);
        cht.add_convex_parabola(1, N - sz[i], dp[i]);
    }

    lint ret2 = stsz * stsz;
    REP(i, sz.size()) mmin(ret2, dp[i] + (stsz - sz[i]) * (stsz - sz[i]));
    return plint(stsz, ret2);
}
int main()
{
    cin >> N;
    if (N == 2)
    {
        puts("2");
        return 0;
    }
    edges.resize(N + 1);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int root = 1;
    REP(i, N + 1) if (edges[i].size() > 1) root = i;
    dfs(root, -1);
    cout << N * (N - 1) - (ret - N) / 2 << endl;
}