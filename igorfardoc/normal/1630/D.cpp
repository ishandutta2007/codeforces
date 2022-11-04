#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool sign(int a) {
    if(a >= 0) return true;
    return false;
}

ll solve(vi& a, int g) {
    int n = a.size();
    ll ans = 0;
    for(int i = 0; i < g; i++) {
        int count = 0;
        int mn = 1000000000;
        for(int j = i; j < n; j+=g) {
            mn = min(mn, abs(a[j]));
            ans += abs(a[j]);
            if(a[j] < 0) ++count;
        }
        if(count % 2 == 1) {
            ans -= 2 * mn;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int g = 0;
        for(int i = 0; i < m; i++) {
            int b;
            cin >> b;
            g = gcd(g, b);
        }
        ll ans = solve(a, g);
        for(int i = 0; i < g; i++) {
            a[i] = -a[i];
        }
        ans = max(ans, solve(a, g));
        cout << ans << '\n';
    }

}