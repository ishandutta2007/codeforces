#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n;
    vector<ll> a(n + 1), suma(n + 1);
    a[0] = 0;
    suma[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        suma[i] = suma[i - 1] + a[i];
    }
    cin >> m;
    vector<ll> b(m + 1), sumb(m + 1);
    b[0] = 0;
    sumb[0] = 0; 
    for(int i = 1; i <= m; i++){
        scanf("%lld", &b[i]);
        sumb[i] = sumb[i - 1] + b[i];
    }
    if(suma[n] != sumb[m]){
        cout << -1 << endl;
        return 0;
    }
    int anow = 0;
    int bnow = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll target = suma[i] - suma[anow] + sumb[bnow];
        auto itr = lower_bound(sumb.begin(), sumb.end(), target);
        if(*itr != target){
            continue;
        }
        ans++;
        anow = i;
        bnow = distance(sumb.begin(), itr);
    }
    printf("%lld\n", ans);
    return 0;
}