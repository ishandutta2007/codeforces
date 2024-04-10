#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map <string, ll> grup;
string str[100005];
ll mincost[100005];
ll cost[100005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    ll ukup=0;
    ll n, k, m;
    cin >> n >> k >> m;
    for(int i=1; i<=n; i++) mincost[i] = 5000000000;
    for(int i=1; i<=n; i++){
        cin >> str[i];
    }
    for(int i=1; i<=n; i++) cin >> cost[i];
    ll x;
    for(int i=1; i<=k; i++){
        cin >> x;
        ll r;
        while(x--){
            cin >> r;
            grup[str[r]] = i;
            mincost[i] = min(mincost[i], cost[r]);
        }
    }
    string stri;
    for(int i=1; i<=m; i++){
        cin >> stri;
        ukup += mincost[grup[stri]];
    }
    cout << ukup;
    return 0;
}