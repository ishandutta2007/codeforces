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
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int N;
vector<int> A;

int main()
{
    cin >> N;
    A.resize(N * 3);
    REP(i, N)
    {
        int a;
        cin >> a;
        A[i] = A[i + N] = A[i + 2 * N] = a;
    }
    vector<int> ret(N * 3 + 1,  (N + 100) * 3);
    deque<pint> deq; // (val, pos)
    IREP(i, 3 * N)
    {
        ret[i] = ret[i + 1];
        auto itr = lower_bound(ALL(deq), pint((A[i] + 1) / 2, 0));
        if (itr != deq.begin())
        {
            mmin(ret[i], prev(itr)->second);
        }
        while (deq.size() and deq.back().first >= A[i]) deq.pop_back();
        deq.emplace_back(A[i], i);
    }
    REP(i, N)
    {
        int t = ret[i] - i;
        if (t > N * 2) t = -1;
        printf("%d ", t);
    }
}