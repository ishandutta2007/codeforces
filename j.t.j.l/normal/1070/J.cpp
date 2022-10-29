#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n, m, K;
char s[MAXN];
int cnt[10000];
int f[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", s);
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    for (int i = 0; i < K; i++){
        cnt[s[i] - 'A']++;
    }
    if (n > m) swap(n, m);
    ll ans = 1ll << 60;
    for (int c = 0; c <= 26; c++){
        for (int i = 0; i <= n; i++)
            f[i] = 0;
        f[0] = 1;
        for (int j = 0; j < 26; j++)
            if (j != c){
                for (int i = n; i >= cnt[j]; i--){
                    f[i] |= f[i - cnt[j]];
                }
            }
        for (int i = 0; i <= n; i++){
            if (f[i] && i + cnt[c] >= n){
                int j = K - cnt[c] - i;
                if (j >= m) j = m;
                if ((m - j) + (n - i) <= cnt[c])
                    ans = min(ans, 1ll * (n - i) * (m - j));
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}