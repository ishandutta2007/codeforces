#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MOD = 1000000007;

int t, n;
int b[MAXN], dp[MAXN];
map <llint, llint> mp;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        llint sum = 0, dp_sum = 1;
        for (int i = n; i >= 1; i--) {
            sum += b[i];
            dp[i] = sub(dp_sum, mp[sum]);
            dp_sum = add(dp_sum, dp[i]);
            mp[sum] = add(mp[sum], dp[i]);
        }
        cout << dp[1] << '\n';
    }
    return 0;
}