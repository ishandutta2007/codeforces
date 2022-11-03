#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    ld p;
    ld ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        ans += p / n;
    }
    cout << setprecision(9) << fixed << ans << endl;
    return 0;
}