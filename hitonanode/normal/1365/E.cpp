#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;




int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint ret = 0;
    REP(i, N)
    {
        chmax(ret, A[i]);
        REP(j, i)
        {
            chmax(ret, A[i] | A[j]);
            REP(k, j)
            {
                chmax(ret, A[i] | A[j] | A[k]);
            }
        }
    }
    cout << ret << '\n';
}