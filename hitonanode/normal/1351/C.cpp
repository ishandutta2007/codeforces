#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        string S;
        cin >> S;
        lint x = 0;
        using P = pair<lint, lint>;
        set<P> visit;
        int ret = 0;
        for (auto c : S)
        {
            lint xprv = x;
            if (c == 'N') x++;
            if (c == 'S') x--;
            if (c == 'E') x += 1e9;
            if (c == 'W') x -= 1e9;
            P p = minmax(xprv, x);
            ret += (visit.count(p) ? 1 : 5);
            visit.insert(p);
        }
        cout << ret << '\n';
    }
}