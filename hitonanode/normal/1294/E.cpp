#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;
    long long int ret = 0;

    REP(m, M) {
        vector<int> cou(N);
        REP(i, N) cou[i] = i + N;
        REP(i, N) {
            int d = A[i][m] - (m + 1);
            if (d < 0 or d % M or d / M >= N) continue;
            else cou[(i + N * 2 - d / M) % N]--;
        }
        ret += *min_element(cou.begin(), cou.end());
    }
    cout << ret << endl;
}