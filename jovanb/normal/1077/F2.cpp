#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll dp[5005][5005];
ll niz[5005];
deque <pair <ll, ll>> q[5005];

const ll INF = 1000000000000007LL;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k, lim;
    cin >> n >> k >> lim;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        if(i <= k) dp[i][1] = niz[i];
        else dp[i][1] = -INF;
    }
    q[1].push_back({niz[1], 1});
    for(int i=2; i<=n; i++){
        for(int x=min(i, lim); x>=2; x--){
            while(!q[x-1].empty()){
                if(q[x-1].front().second < i-k) q[x-1].pop_front();
                else{
                    dp[i][x] = niz[i]+q[x-1].front().first;
                    break;
                }
            }
            if(q[x-1].empty()) dp[i][x] = -INF;
            else{
                while(!q[x].empty()){
                    if(q[x].back().first <= dp[i][x]) q[x].pop_back();
                    else break;
                }
                q[x].push_back({dp[i][x], i});
            }
        }
        if(i <= k){
            while(!q[1].empty()){
                if(q[1].back().first <= niz[i]) q[1].pop_back();
                else break;
            }
            q[1].push_back({niz[i], i});
        }
    }
    ll mx=-INF;
    for(int i=n-k+1; i<=n; i++){
        mx = max(mx, dp[i][lim]);
    }
    if(mx <= 0) cout << -1;
    else cout << mx;
    return 0;
}