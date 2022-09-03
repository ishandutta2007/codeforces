#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<lint> solve(vector<int> v) {
    int N = v.size();
    using P = pair<pint, lint>;
    vector<P> st;
    vector<lint> ret(N);
    lint val = 0;
    REP(i, N)
    {
        int l = i;
        while (st.size() and st.back().first.first >= v[i]) {
            int h, j;
            tie(h, j) = st.back().first;
            lint vt = st.back().second;
            mmin(l, j);
            st.pop_back();
            val -= vt;
        }
        st.emplace_back(pint(v[i], l), 1LL * v[i] * (i - l + 1));
        val += st.back().second;
        ret[i] = val;
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<int> M(N);
    cin >> M;
    vector<lint> v1 = solve(M);
    reverse(M.begin(), M.end());
    vector<lint> v2 = solve(M);
    reverse(M.begin(), M.end());
    reverse(v2.begin(), v2.end());
    vector<lint> val(N);
    REP(i, N) val[i] = v1[i] + v2[i] - M[i];
    int i = max_element(val.begin(), val.end()) - val.begin();
    vector<int> ret(N, M[i]);
    IREP(j, i) ret[j] = min(ret[j + 1], M[j]);
    FOR(j, i + 1, N) ret[j] = min(ret[j - 1], M[j]);
    for (auto x : ret) printf("%d ", x);
    puts("");
}