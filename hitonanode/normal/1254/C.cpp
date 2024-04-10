#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int ask_sgn(int i, int j, int k)
{
    printf("2 %d %d %d\n", i, j, k);
    fflush(stdout);
    int t;
    cin >> t;
    if (t == -1) t = 0;
    return t;
}

map<int, lint> area_mem;
lint ask_area(int i, int j, int k)
{
    printf("1 %d %d %d\n", i, j, k);
    fflush(stdout);
    lint area;
    cin >> area;
    if (i == 1 and j == 2) area_mem[k] = area;
    return area;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> updn(2);
    vector<int> hi(2, -1);
    FOR(n, 3, N + 1)
    {
        // dbg(updn);
        // dbg(hi);
        int sgn = ask_sgn(1, 2, n);
        lint area = ask_area(1, 2, n);

        if (hi[sgn] < 0)
        {
            hi[sgn] = n;
            updn[sgn].emplace_back(n);
            continue;
        }
        int sgn2 = ask_sgn(1, hi[sgn], n);
        if (sgn2 == 1)
        {
            int i = 0;
            while (updn[sgn][i] != hi[sgn]) i++;
            i++;
            while (i < (int)updn[sgn].size() and area_mem[updn[sgn][i]] > area) i++;
            updn[sgn].insert(updn[sgn].begin() + i, n);
        }
        else
        {
            int i = 0;
            while (updn[sgn][i] != hi[sgn]) i++;
            while (i > 0 and area_mem[updn[sgn][i - 1]] > area) i--;
            updn[sgn].insert(updn[sgn].begin() + i, n);
        }

        if (area > area_mem[hi[sgn]]) hi[sgn] = n;
    }
    printf("0 1");
    for (auto x : updn[0]) printf(" %d", x);
    printf(" 2");
    for (auto x : updn[1]) printf(" %d", x);
    puts("");
}