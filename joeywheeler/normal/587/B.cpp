#include <bits/stdc++.h>

#define FO(i,a,b) for (long long i = (a); i < (b); i++)
#define sz(v) long long(v.size())

#define MOD 1000000007

using namespace std;

long long n, k, l;
long long a[1000005];
long long cnt[1000005];
long long cnt2[1000005];

long long dp[1000005];
long long dp2[1000005];

int main() {
    scanf("%lld%lld%lld", &n, &l, &k);
    FO(i,0,n) {
        scanf("%lld", &a[i]);
    }
    vector<long long> A(a,a+n);
    sort(A.begin(),A.end());
    A.resize(unique(A.begin(),A.end())-A.begin());
    FO(i,0,n) {
        a[i] = lower_bound(A.begin(),A.end(),a[i])-A.begin();
        cnt[a[i]]++;
        if (i < l%n) cnt2[a[i]]++;
    }

    long long f = (l/n)*n;

    dp[0] = 1;
    long long res = 0;
    FO(Z,1,k+1) {
        if (f/n >= Z-1) {
            FO(i,0,n) {
                dp2[i] = dp[i];
            }
            FO(i,0,n) {
                dp2[i+1] += dp2[i];
                if (dp2[i+1] >= MOD) dp2[i+1] -= MOD;
            }
            FO(i,0,n) {
                dp2[i] = (dp2[i]*1ll*cnt2[i]) % MOD;
            }
            long long tot = 0;
            FO(i,0,n) {
                tot += dp2[i];
                if (tot >= MOD) tot -= MOD;
            }
            res += tot;
            res %= MOD;
        }


        FO(i,0,n) {
            dp[i+1] += dp[i];
            if (dp[i+1] >= MOD) dp[i+1] -= MOD;
        }
        FO(i,0,n) {
            dp[i] = (dp[i]*1ll*cnt[i]) % MOD;
        }
        long long tot = 0;
        FO(i,0,n) {
            tot += dp[i];
            if (tot >= MOD) tot -= MOD;
        }
        if (f/n-Z+1 > 0) {
            res = (res + (f/n - Z + 1) % MOD * 1ll * tot) % MOD;
        }
    }
    printf("%lld\n", res);
}