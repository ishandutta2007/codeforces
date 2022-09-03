#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////



int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    map<int, set<int>> ma;
    REP(i, N) ma[A[i]].insert(i);

    int ret = N;

    int mustL = N, mustR = 0;
    set<int> req;
    for (auto p : ma) if (p.second.size() > 1)
    {
        req.insert(*p.second.begin());
        if (p.second.size() > 2)
        {
            mmin(mustL, *next(p.second.begin()));
            mmax(mustR, *prev(p.second.end(), 2));
        }
    }
    if (req.empty())
    {
        puts("0");
        return 0;
    }
    REP(i, N)
    {
        int reqL = min(mustL, *req.begin());
        int reqR = max(mustR, *prev(req.end()));
        int tmp = reqR - reqL + 1;
        ret = min(ret, tmp);

        req.erase(i);
        if (ma[A[i]].size() > 1) req.insert(*prev(ma[A[i]].end()));
    }
    cout << ret << endl;
}