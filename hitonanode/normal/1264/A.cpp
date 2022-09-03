#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve()
{
    int N;
    cin >> N;
    vector<int> P(N);
    cin >> P;

    if (N < 10)
    {
        puts("0 0 0");
        return;
    }
    int g = 0;
    int maxi = N / 2;
    while (maxi > 0 and P[maxi] == P[maxi - 1]) maxi--;
    while (g < (int)P.size() and P[g] == P[0]) g++;
    if (g * 3 >= (int)P.size())
    {
        puts("0 0 0");
        return;
    }
    int s = g * 2 + 1;
    while (s < (int)P.size() and P[s] == P[s - 1]) s++;
    if (s >= (int)P.size())
    {
        puts("0 0 0");
        return;
    }
    int b = s + g + 1;
    while (b < (int)P.size() and P[b] == P[b - 1]) b++;
    if (b >= (int)P.size())
    {
        puts("0 0 0");
        return;
    }
    int r1 = g, r2 = s - g, r3 = max(b, maxi) - s;
    if (r1 > 0 and r2 > 0 and r3 > 0 and (r1 + r2 + r3) * 2 <= N)
    {
        printf("%d %d %d\n", r1, r2, r3);
    }
    else
    {
        puts("0 0 0");
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}