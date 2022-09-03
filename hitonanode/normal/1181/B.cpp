#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

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

int N;
string S;

int main()
{
    cin >> N >> S;
    int d1 = (N + 1) / 2, d2 = N / 2;
    while (d1 < S.length() and S[d1] == '0') d1++;
    while (d2 >= 0 and S[d2] == '0') d2--;

    vector<mpint> vec;
    dbg(d1);
    dbg(d2);
    if (d1 < S.length())
    {
        mpint a1(S.substr(0, d1)), a2(S.substr(d1));
        vec.push_back(a1 + a2);
    }
    if (d2 > 0)
    {
        mpint b1(S.substr(0, d2)), b2(S.substr(d2));
        vec.push_back(b1 + b2);
    }
    sort(ALL(vec));
    dbg(vec);
    cout << vec[0] << endl;
}