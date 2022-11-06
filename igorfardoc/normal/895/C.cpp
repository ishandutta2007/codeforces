#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
const int am = 19;
const int maxn = 70;
const int mod = 1000000007;
int p[200000];
int get_mask(int a) {
    int ans = 0;
    for(int i = 0; i < am; i++) {
        int here = 0;
        while(a % primes[i] == 0) {
            ++here;
            a /= primes[i];
        }
        here %= 2;
        ans ^= (here << i);
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
    p[0] = 1;
    for(int i = 1; i < 200000; i++) {
        p[i] = p[i - 1] * 2 % mod;
    }
    int n;
    cin >> n;
    vi amount(maxn + 1, 0);
    vvi dp(maxn + 1, vi(1 << am));
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        amount[a]++;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= 70; i++) {
        int mask1 = get_mask(i);
        for(int mask = 0; mask < (1 << 19); mask++) {
            int here = amount[i];
            int can1 = 0;
            if(here != 0) {
                can1 = p[here - 1];
            }
            dp[i][mask] = ((ll)dp[i - 1][mask] * p[max(here - 1, 0)] + (ll)dp[i - 1][mask ^ mask1] * can1) % mod;
        }
    }
    cout << (mod - 1 + dp[70][0]) % mod;
}