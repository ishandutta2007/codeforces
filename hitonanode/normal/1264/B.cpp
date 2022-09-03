#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void NO()
{
    puts("NO");
    exit(0);
}

int main()
{
    vector<int> V(4);
    cin >> V;
    vector<int> ret;
    int e = V[0] + V[2];
    int o = V[1] + V[3];
    if (abs(e - o) > 1) NO();
    int now = 0;
    if (e > o)
    {
        if (V[0]) now = 0;
        else now = 2;
    }
    else if (e < o)
    {
        if (V[1]) now = 1;
        else now = 3;
    }
    else
    {
        while (V[now] == 0) now++;
    }
    while (true)
    {
        if (V[now] == 0) break;
        ret.emplace_back(now);
        V[now]--;

        if (now == 1 and V[now - 1])
        {
            now--;
            continue;
        }
        if (now == 2 and V[now + 1])
        {
            now++;
            continue;
        }
        if (now == 3)
        {
            now--;
            continue;
        }
        if (now == 0)
        {
            now++;
            continue;
        }

        if (V[now - 1])
        {
            now--;
            continue;
        }
        else
        {
            now++;
            continue;
        }
    }
    if (accumulate(ALL(V), 0) == 0)
    {
        puts("YES");
        for (auto v : ret)
        {
            printf("%d ", v);
        }
    }
    else NO();
}