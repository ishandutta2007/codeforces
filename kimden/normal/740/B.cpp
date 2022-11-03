#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[102];
pii x[102];
ll pref[102];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> x[i].first >> x[i].second;
    }
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    sort(x, x + m, [](pii& lhs, pii& rhs) -> bool{
            ll p1 = pref[lhs.second] - pref[lhs.first - 1];
            ll p2 = pref[rhs.second] - pref[rhs.first - 1];
            if(p1 == p2){
                return lhs < rhs;
            }
            return p1 > p2;
         }
    );
    ll p;
    ll ans = 0;
    for(int i = 0; i < m; i++){
        p = pref[x[i].second] - pref[x[i].first - 1];
        if(p <= 0){
            break;
        }
        ans += p;
    }
    cout << ans << endl;

    return 0;
}