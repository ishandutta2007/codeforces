#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

void solve()
{
    lint N, K;
    cin >> N >> K;
    string ret(N, 'a');
    lint lo = 0, hi = N;
    while (hi - lo > 1) {
        int c = (lo + hi) / 2;
        lint yo = N - c;
        lint nb = yo * (yo - 1) / 2;
        if (nb >= K) lo = c;
        else hi = c;
    }
    ret[lo] = 'b';
    lint yo = N - lo - 1;
    lint nb = yo * (yo - 1) / 2;
    K -= nb;
    ret[ret.size() - K] = 'b';
    cout << ret << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}