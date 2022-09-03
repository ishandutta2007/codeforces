#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
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

int query(vector<int> v)
{
    cout << v.size();
    for (auto x : v) cout << ' ' << x + 1;
    cout << endl;
    int ret;
    cin >> ret;
    if (ret < 0) exit(0);
    return ret - 1;
}

int main()
{
    int N;
    cin >> N;

    int goal = 0;
    int K = 0;
    int L = 0;
    FOR(l, 1, N + 1)
    {
        int k = N / l;
        if (k < l) continue;
        int rem = N - k * l;
        int b = max(rem - 1, 0);
        if (chmax(goal, (k - 1) * (l - 1) + b)) K = k, L = l;
    }

    FOR(k, 1, N + 1)
    {
        int l = N / k;
        int rem = N - k * l;
        int b = max(rem - 1, 0);
        if (k < l) continue;
        if (chmax(goal, (k - 1) * (l - 1) + b)) K = k, L = l;
    }

    vector<int> state(N);

    vector<int> cand;
    REP(j, L - 1)
    {
        int i = 0;
        while (true)
        {
            int now = i * L + j;
            if (now >= N - 1) break;
            cand.emplace_back(now);
            i++;
        }
    }
    // dbg(K);
    // dbg(L);
    // dbg(goal);
    // dbg(cand);
    while (true)
    {
        int now = accumulate(state.begin(), state.end(), 0);
        if (now >= goal)
        {
            cout << 0 << endl;
            return 0;
        }
        vector<int> qvec;
        for (auto x : cand)
        {
            if (!state[x]) qvec.emplace_back(x), state[x] = 1;
            if (qvec.size() == L) break;
        }
        int rep = query(qvec);
        FOR(i, rep, rep + qvec.size())
        {
            state[i % N] = 0;
        }
    }
}