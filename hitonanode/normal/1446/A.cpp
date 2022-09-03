#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

void solve()
{
    int N;
    lint W;
    cin >> N >> W;
    vector<lint> V(N);
    for (auto &x : V) {
        cin >> x;
    }
    const lint t = (W + 1) / 2;

    vector<int> ret;
    lint cum = 0;

    REP(i, N) {
        if (V[i] >= t and V[i] <= W) {
            cout << "1\n" << i + 1 << '\n';
            return;
        }
        if (V[i] + cum <= W) {
            cum += V[i];
            ret.emplace_back(i + 1);
        }
    }
    if (cum >= t) {
        cout << ret.size() << '\n';
        for (auto x:  ret) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}