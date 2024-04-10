#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    cin >> H;
    vector<int> D(N, N);
    D[0] = D.back() = 1;
    REP(i, N - 1)
    {
        chmin(D[i + 1], D[i] + 1);
        chmin(D[i + 1], H[i + 1]);
    }
    IREP(i, N - 1)
    {
        chmin(D[i], D[i + 1] + 1);
    }
    cout << *max_element(D.begin(), D.end()) << '\n';
}