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
    map<int, int> ma;
    REP(i, N)
    {
        int tmp;
        cin >> tmp;
        ma[tmp]++;
    }
    vector<int> A;
    for (auto pa : ma) A.push_back(pa.first);
    N = A.size();
    sort(A.begin(), A.end());
    int ret = 0;
    IREP(i, N)
    {
        mmax(ret, A[i]);
        int j = i;
        while (true)
        {
            while (j >= 0 and A[i] % A[j] == 0) j--;
            if (j < 0) break;
            mmax(ret, A[i] + A[j]);
            int k = j;
            while (k >= 0 and (A[i] % A[k] == 0 or A[j] % A[k] == 0)) k--;
            if (k < 0 or A[i] + A[j] + A[k] < ret) break;
            mmax(ret, A[i] + A[j] + A[k]);
            j--;
        }
    }
    cout << ret << endl;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q) solve();
}