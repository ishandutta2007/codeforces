#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int main()
{
    int W, L;
    cin >> W >> L;
    vector<int> A(W + 1);
    FOR(w, 1, W) cin >> A[w];
    A.back() = 1.1e9;
    vector<int> current(W + 1);
    current[0] = 1.1e9;
    int l = 0;
    FOR(i, 1, W + 1)
    {
        while (i - l > L) l++;
        while (true) {
            if (l == i or !A[i]) break;
            if (!current[l]) {
                l++;
                continue;
            }
            int mv = min(A[i], current[l]);
            current[i] += mv;
            current[l] -= mv;
            A[i] -= mv;
        }
    }
    cout << current.back() << "\n";
}