#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[10000];
ll cost[10000];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++) cin >> cost[i];
    ll mincost = 1000000000;
    for(int i=2; i<n; i++){
        ll mini1 = 1000000000;
        for(int j=i-1; j>=1; j--){
            if(niz[j] < niz[i]) mini1 = min(mini1, cost[j]);
        }
        ll mini2 = 1000000000;
        for(int j=i+1; j<=n; j++){
            if(niz[j] > niz[i]) mini2 = min(mini2, cost[j]);
        }
        mincost = min(mincost, mini1+mini2+cost[i]);
        
    }
    if(mincost == 1000000000) cout << "-1";
    else cout << mincost;
    return 0;
}