#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll niz[300005];
ll pre[300005];
ll suf[300005];
ll sum[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, x;
    cin >> n >> x;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        sum[i] = sum[i-1] + niz[i];
        pre[i] = pre[i-1] + niz[i];
        pre[i] = max(pre[i], 0LL);
    }
    for(int i=n; i>=1; i--){
        suf[i] = suf[i+1] + niz[i];
        suf[i] = max(0LL, suf[i]);
    }
    ll best = 0;
    ll mx = 0;
    for(int i=0; i<=n; i++){
        mx = max(mx, suf[i+1] + x*sum[i] + best);
        best = max(best, pre[i] - x*sum[i]);
    }
    cout << mx;
    return 0;
}