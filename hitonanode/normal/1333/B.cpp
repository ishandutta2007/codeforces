#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

bool solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    cin >> A >> B;
    vector<int> cp(N + 1), cm(N + 1);
    REP(i, N) {
        cp[i + 1] = cp[i], cm[i + 1] = cm[i];
        if (A[i] == 1) cp[i + 1] = 1;
        if (A[i] == -1) cm[i + 1] = 1;
        if (A[i] < B[i] and !cp[i]) return false;
        if (A[i] > B[i] and !cm[i]) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "YES\n" : "NO\n");
}