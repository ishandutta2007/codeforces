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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int solve(const string &S, int K, char a, char b, char c)
{
    vector<char> v{a, b, c};
    int N = S.length();
    int bad = 0;
    int ret = K;
    REP(i, K - 1) if (S[i] != v[i % 3]) bad++;
    FOR(i, K - 1, N)
    {
        if (S[i] != v[i % 3]) bad++;
        mmin(ret, bad);
        if (S[i - (K - 1)] != v[(i - (K - 1)) % 3]) bad--;
    }
    return ret;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        int ret = N;
        ret = min(ret, solve(S, K, 'R', 'G', 'B'));
        ret = min(ret, solve(S, K, 'G', 'B', 'R'));
        ret = min(ret, solve(S, K, 'B', 'R', 'G'));
        printf("%d\n", ret);
    }
}