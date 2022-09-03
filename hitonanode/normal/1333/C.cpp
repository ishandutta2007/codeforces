#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

int main()
{
    int N;
    cin >> N;
    map<lint, int> mp;
    mp[0] = 1;
    lint ret = 1LL * N * (N + 1) / 2;
    lint ac = 0;
    int lo = 0;
    for (int t = 2; t <= N + 1; t++) {
        int a;
        cin >> a;
        ac += a;
        lo = max(lo, mp[ac]);
        ret -= lo;
        mp[ac] = t;
    }
    cout << ret << "\n";
}