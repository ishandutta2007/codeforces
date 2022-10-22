#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;
ll modpow[200001];
vector<int> bonus(31);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    modpow[0] = 1;
    for(int i = 1; i <= 200000; i++) modpow[i] = (2 * modpow[i-1]) % MOD;
    for(int i = 0; i <= 30; i++) bonus[i] = 0;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int odds = 0;
    for(int i = 0; i < n; i++) if(nums[i]%2) odds++;
    ll ans = (modpow[n] - modpow[n-odds] + MOD) % MOD;
    for(int i = 0; i < n; i++) {
        int g = 0;
        while(!(nums[i]%2)) {
            nums[i] /= 2;
            g++;
        }
        if(g) bonus[g]++;
    }
    for(int i = 1; i <= 30; i++) {
        ll g = 0;
        if(bonus[i] >= 2) {
            g = modpow[bonus[i]-1] - 1;
            g += MOD;
            g %= MOD;
            for(int j = i+1; j <= 30; j++) {
                g *= modpow[bonus[j]];
                g %= MOD;
            }
        }
        ans += g;
        ans %= MOD;
    }
    cout << ans << '\n';
}