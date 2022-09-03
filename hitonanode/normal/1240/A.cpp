#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


void solve()
{
    int N;
    cin >> N;
    vector<lint> p(N);
    cin >> p;
    sort(p.rbegin(), p.rend());
    lint X, A, Y, B, K;
    cin >> X >> A >> Y >> B >> K;

    int l = 0, r = N + 1; // lr
    while (r - l > 1)
    {
        int c = (l + r) / 2;
        lint k = K;
        bool flg = false;
        priority_queue<lint> pq;
        FOR(i, 1, c + 1) pq.emplace((i % A == 0) * X + (i % B == 0) * Y);

        for (auto v : p)
        {
            if (pq.empty()) break;
            k -= pq.top() * (v / 100);
            pq.pop();
            if (k <= 0)
            {
                flg = true;
                break;
            }
        }
        (flg ? r : l) = c;
    }
    cout << (r == N + 1 ? -1 : r) << endl;
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        solve();
    }
}