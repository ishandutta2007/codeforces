#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve()
{
    int N;
    cin >> N;
    vector<int> T(N);
    cin >> T;
    if (*max_element(ALL(T)) == *min_element(ALL(T))) {
        puts("1");
        REP(i, N) printf("1 ");
        puts("");
        return;
    }
    if (N % 2 == 0) {
        puts("2");
        REP(i, N) printf("%d ", i % 2 + 1);
        puts("");
        return;
    }
    int is = -1;
    REP(i, N) if (T[i] == T[(i + 1) % N]) is = (i + 1) % N;
    if (is < 0) {
        puts("3");
        printf("3");
        REP(i, N - 1) printf(" %d", i % 2 + 1);
        puts("");
        return;
    }
    int st = 0;
    puts("2");
    REP(i, N) {
        if (i != is) st = !st;
        printf("%d ", st + 1);
    }
    puts("");
}

int main()
{
    int Q;
    cin >> Q;
    while (Q--) solve();
}