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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

int N;
string S;

void check_valid()
{
    int a = 0, b = 0;
    for (auto c : S) if (c == '(') a++;
    else b++;
    if (a != b)
    {
        puts("0\n1 1");
        exit(0);
    }
}

int main()
{
    cin >> N >> S;
    check_valid();
    vector<int> acc(N);
    REP(i, N - 1)
    {
        if (S[i] == '(') acc[i + 1] = acc[i] + 1;
        else acc[i + 1] = acc[i] - 1;
    }
    int lo = *min_element(ALL(acc));
    vector<int> lo_pos;
    deque<pair<int, pint>> lop1s;
    deque<pair<int, pint>> lop2s;
    int cou_lop1 = 0, l_lop1 = 0;
    int cou_lop2 = 0, l_lop2 = 0;

    REP(i, N * 2)
    {
        if (acc[i % N] == lo)
        {
            lo_pos.push_back(i);
            if (cou_lop1) lop1s.emplace_back(cou_lop1, pint(l_lop1, i)), cou_lop1 = 0;
            l_lop1 = i;
            if (cou_lop2) lop2s.emplace_back(cou_lop2, pint(l_lop2, i)), cou_lop2 = 0;
            l_lop2 = i;
        }
        if (acc[i % N] == lo + 2)
        {
            cou_lop2++;
        }
        if (acc[i % N] == lo + 1)
        {
            cou_lop1++;
            if (cou_lop2) lop2s.emplace_back(cou_lop2, pint(l_lop2, i)), cou_lop2 = 0;
            l_lop2 = i;
        }
    }
    while (!lop1s.empty() and lop1s.front().second.first < lo_pos[0]) lop1s.pop_front();
    while (!lop2s.empty() and lop2s.front().second.first < lo_pos[0]) lop2s.pop_front();
    while (!lop1s.empty() and lop1s.back().second.second > lo_pos.back()) lop1s.pop_back();
    while (!lop2s.empty() and lop2s.back().second.second > lo_pos.back()) lop2s.pop_back();
    sort(ALL(lop1s));
    sort(ALL(lop2s));

    int ret_sumlo1 = 0, ret_sumlo0 = lo_pos.size() / 2;
    if (!lop1s.empty()) ret_sumlo1 = lop1s.back().first;
    if (!lop2s.empty()) ret_sumlo0 += lop2s.back().first;

    if (ret_sumlo1 > ret_sumlo0)
    {
        dbg("Case 1");
        cout << ret_sumlo1 << endl;
        cout << lop1s.back().second.first % N + 1 << " " << (lop1s.back().second.second + N - 1) % N + 1 << endl;
    }
    else
    {
        dbg("Case 2");
        cout << ret_sumlo0 << endl;
        if (lop2s.empty()) cout << "1 1" << endl;
        else
        {
            cout << lop2s.back().second.first % N + 1 << " " << (lop2s.back().second.second + N - 1) % N + 1 << endl;
        }
    }
}