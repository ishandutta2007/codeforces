#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx")
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


using Matrix = vector<lint>;
constexpr lint DIM = 4;
vector<lint> matmul(const vector<lint> &A, const vector<lint> &B, lint mod = 1000000007)
{
    vector<lint> C(16);
    REP(i, 4) REP(j, 4) REP(k, 4) C[i * 4 + j] += A[i * 4 + k] * B[k * 4 + j];
    REP(i, 16) C[i] %= mod;
    return C;
}

int main()
{
    int M;
    cin >> M;
    string S;
    REP(_, M)
    {
        char c;
        cin >> c;
        S += c;
    }
    vector<Matrix> Ms(M);
    REP(i, M)
    {
        Ms[i] = vector<lint>{
        1, 1, 1, 1,
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0};
        if (i >= 3)
        {
            string T = S.substr(i - 3, 4);
            if (
                T == "0011" or
                T == "0101" or
                T == "1110" or
                T == "1111"
            ) Ms[i][0 * 4 + 3] = 0;
        }
    }
    Matrix M0(16);
    REP(d, 4) M0[d * 4 + d] = 1;

    lint ret = 0;
    vector<pint> to(1, {-1, -1});

    FOR(r, 1, M + 1)
    {
        int now = 0;
        bool flg = true;
        Matrix M = M0;
        IREP(l, r)
        {
            int nxt = (S[l] == '0' ? to[now].first : to[now].second);
            if (nxt == -1)
            {
                flg = false;
                nxt = to.size();
                to.emplace_back(-1, -1);
                (S[l] == '0' ? to[now].first : to[now].second) = nxt;
            }
            now = nxt;
            M = matmul(M, Ms[l]);
            if (flg) continue;
            ret += M[0 * 4 + 0];
        }
        ret %= 1000000007;
        printf("%lld\n", ret);
    }
}