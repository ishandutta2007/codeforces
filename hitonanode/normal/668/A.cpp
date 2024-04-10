#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }


int main()
{
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> query;
    while (Q--) {
        int t, x;
        cin >> t >> x;
        if (t == 3) {
            int y, z;
            cin >> y >> z;
            query.push_back({ t, x, y, z });
        }
        else {
            query.push_back({ t, x });
        }
    }

    vector ret(H, vector(W, 0));
    reverse(query.begin(), query.end());
    for (const auto vec : query) {
        if (vec[0] == 3) {
            ret[vec[1] - 1][vec[2] - 1] = vec.back();
        } else if (vec[0] == 1) {
            const int h = vec[1] - 1;
            std::rotate(ret[h].begin(), ret[h].end() - 1, ret[h].end());
        } else {
            const int w = vec[1] - 1;
            int z = ret.back()[w];
            IREP(i, H - 1) ret[i + 1][w] = ret[i][w];
            ret[0][w] = z;
        }
    }
    for (auto vec : ret) {
        for (auto x : vec) cout << x << ' ';
        cout << '\n';
    }
}