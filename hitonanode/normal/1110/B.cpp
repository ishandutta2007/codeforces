#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> B(N);
    cin >> B;
    vector<int> diff;
    REP(i, N - 1) diff.push_back(B[i + 1] - B[i] - 1);
    sort(ALL(diff));
    cout << N + accumulate(diff.begin(), diff.begin() + N - K, 0) << endl;
}