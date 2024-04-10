#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


void solve()
{
    int N;
    cin >> N;
    lint su = 1;
    int t = 0;
    while (su < N)
    {
        t++;
        su += 1 << t;
    }
    vector<int> ret(t);
    N -= t + 1;
    int k = 1;
    for (int i = 0; i < t; i++)
    {
        int r = min(k, N / (t - i));
        k += r;
        N -= r * (t - i);
        ret[i] = r;
    }
    cout << t << '\n';
    for (auto x : ret) cout << x <<' ';
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}