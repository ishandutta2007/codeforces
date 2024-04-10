#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N), F(N);
    REP(i, N) cin >> A[i] >> F[i];
    map<int, pint> ma;
    REP(i, N)
    {
        ma[A[i]].first++;
        if (F[i]) ma[A[i]].second++;
    }
    
    priority_queue<pint> pqp;
    priority_queue<int> pqi;
    
    for (auto pa : ma) pqp.emplace(pa.second);
    
    lint ret1 = 0, ret2 = 0;
    
    int nnow = 1e9;
    while (true)
    {
        if (pqp.empty() and pqi.empty()) break;
        
        if (pqi.empty())
        {
            pqi.push(pqp.top().second);
            mmin(nnow, pqp.top().first);
            pqp.pop();
        }
        else nnow--;
        while (!pqp.empty() and pqp.top().first >= nnow)
        {
            pqi.push(pqp.top().second);
            pqp.pop();
        }
        if (nnow <= 0) break;
        ret1 += nnow;
        ret2 += min(nnow, pqi.top());
        pqi.pop();
    }
    cout << ret1 << " " << ret2 << endl;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q) solve();
}