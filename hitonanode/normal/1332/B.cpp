#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> prs{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<int> used(11);
    for (auto &x : A) {
        REP(i, prs.size()) if (x % prs[i] == 0) {
            used[i] = 1;
            x = i;
            break;
        }
    }
    int cnt = 0;
    REP(d, used.size()) if (used[d]) {
        for (auto &x : A) if (x == d) x = cnt;
        cnt++;
    }
    printf("%d\n", cnt);
    for (auto x : A) printf("%d ", x + 1);
    puts("");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}