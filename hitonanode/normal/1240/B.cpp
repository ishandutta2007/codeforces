#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    map<int, int> first, last;
    REP(i, N)
    {
        if (!first.count(A[i])) first[A[i]] = i;
        last[A[i]] = i;
    }

    sort(ALL(A));
    A.erase(unique(A.begin(), A.end()), A.end());
    int maxsuc = 1;
    int suc = 1;
    FOR(i, 1, A.size())
    {
        if (last[A[i - 1]] <= first[A[i]])
        {
            suc++;
            maxsuc = max(maxsuc, suc);
        }
        else suc = 1;
    }
    cout << A.size() - maxsuc << endl;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q) solve();
}