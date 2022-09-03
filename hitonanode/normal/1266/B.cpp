#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


int main()
{
    int T;
    cin >> T;
    while (T--) {
        lint X;
        cin >> X;
        if (X <= 14)
        {
            puts("NO");
            continue;
        }
        X %= 14;
        if (1 <= X and X <= 6) puts("YES");
        else puts("NO");
    }
}