#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

void solve()
{
    int N;
    cin >> N;
    vector<int> ret;
    while (N--)
    {
        int p;
        cin >> p;
        if (ret.size() < 2) ret.emplace_back(p);
        else
        {
            bool b1 = ret.back() < p;
            bool b2 = ret[ret.size() - 2] < ret.back();
            if (!(b1 ^ b2)) ret.pop_back();

            ret.emplace_back(p);
        }
    }
    cout << ret.size() << '\n';
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}