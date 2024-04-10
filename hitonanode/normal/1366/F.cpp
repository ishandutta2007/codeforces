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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

plint cross_x(plint p, plint q)
{
    plint ret(q.second - p.second, p.first - q.first);
    if (ret.second < 0) ret.first *= -1, ret.second *= -1;
    return ret;
}

constexpr int MOD = 1000000007;
lint solve(lint l, lint r, plint p)
{
    lint ret = (p.second % MOD + MOD) * (r - l) + (p.first % MOD + MOD) * (((1LL * r * (r + 1) - l * (l + 1)) / 2) % MOD);
    return ret;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pint> ab;

    vector<int> maxl(N);
    vector<vector<pint>> to(N);
    lint ret = 0;
    while (M--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        REP(_, 2)
        {
            to[a].emplace_back(b, w);
            chmax(maxl[a], w);
            swap(a, b);
        }
    }
    vector<int> D(N, -1);
    D[0] = 0;
    REP(t, N)
    {
        vector<int> Dnxt(N, -1);
        REP(i, N) if (D[i] >= 0)
        {
            for (auto [j, w] : to[i])
            {
                chmax(Dnxt[j], D[i] + w);
            }
        }
        D = Dnxt;
        REP(i, N) if (D[i] >= 0) ab.emplace_back(maxl[i], D[i] - maxl[i] * (t + 1));
        if (t + 1 <= Q) (ret += *max_element(D.begin(), D.end())) %= MOD;
    }
    sort(ab.begin(), ab.end());
    vector<pint> abn;
    for (auto p : ab)
    {
        if (abn.empty()) abn.emplace_back(p);
        else
        {
            while (abn.size() > 1)
            {
                if (abn.back().first == p.first)
                {
                    abn.pop_back();
                    continue;
                }
                plint xprv = cross_x(abn[abn.size() - 2], abn.back());
                plint xnow = cross_x(abn.back(), p);
                if (xprv.first * xnow.second >= xnow.first * xprv.second)
                {
                    abn.pop_back();
                    continue;
                }

                break;
            }

            if (abn.size() == 1 and abn.back().first == p.first)
            {
                abn.back() = p;
            }
            else
            {
                abn.emplace_back(p);
            }
        }
    }

    lint T = N;
    if (T < Q)
    {
        REP(i, abn.size() - 1)
        {
            plint c = cross_x(abn[i], abn[i + 1]);
            lint TNXT = clamp<lint>(c.first / c.second, T, Q);
            (ret += solve(T, TNXT, abn[i])) %= MOD;
            T = TNXT;
        }
        (ret += solve(T, Q, abn.back())) %= MOD;
    }

    cout << ret << '\n';
}