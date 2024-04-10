#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, k, ans;

int main(){
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if(k > n + m - 2){puts("-1"); return 0;}
    for(ll i = 1; i * i <= n; i++){
        if(n % i) continue;
        if(i - 1 <= k) ans = max(ans, (n / i) * (m / (k - i + 2ll)));
        if((n / i) - 1 <= k) ans = max(ans, (n / (n / i)) * (m / (k - (n / i) + 2ll)));
    }
    for(ll i = 1; i * i <= m; i++){
        if(m % i) continue;
        if(i - 1 <= k) ans = max(ans, (m / i) * (n / (k - i + 2ll)));
        if((m / i) - 1 <= k) ans = max(ans, (m / (m / i)) * (n / (k - (m / i) + 2ll)));
    }
    printf("%I64d", ans);
}