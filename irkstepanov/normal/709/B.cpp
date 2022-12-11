#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

const int inf = 1e9;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a;
    cin >> n >> a;
    
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(all(x));
    
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    
    if (a <= x[0]) {
        cout << x[n - 2] - a << "\n";
        return 0;
    }
    if (a >= x[n - 1]) {
        cout << a - x[1] << "\n";
        return 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (a >= x[i] && a <= x[i + 1]) {
            int ans = abs(a - x[0]) + abs(x[n - 2] - x[0]);
            ans = min(ans, abs(x[n - 2] - a) + abs(x[n - 2] - x[0]));
            ans = min(ans, abs(a - x[1]) + abs(x[n - 1] - x[1]));
            ans = min(ans, abs(x[n - 1] - a) + abs(x[n - 1] - x[1]));
            cout << ans << "\n";
            return 0;
        }
    }

}