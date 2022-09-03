#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void NO()
{
    puts("No");
    exit(0);
}

int main()
{
    int N;
    cin >> N;
    vector<int> C(N), T(N);
    cin >> C >> T;
    if (C[0] != T[0] or C.back() != T.back()) NO();

    vector<int> CD(N - 1), TD(N - 1);
    REP(i, N - 1) CD[i] = C[i + 1] - C[i], TD[i] = T[i + 1] - T[i];
    sort(ALL(CD));
    sort(ALL(TD));
    if (CD != TD) NO();
    puts("Yes");
}