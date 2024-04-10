#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return _gcd(b, a % b);
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
        int n;
        cin >> n;
        int ans = 1;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ans = max(ans, n / i);
                ans = max(ans, i);
            }
        }
        cout << ans << ' ' << n - ans << '\n';
    }
}