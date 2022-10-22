#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> vec[25];
ll dp[2000005];
ll cost[25][25];

const ll INF = 1000000000000000000LL;

ll inv(int a, int b){
    int tren = -1;
    int k = vec[b].size();
    ll res = 0;
    for(auto c : vec[a]){
        while(tren < k-1 && vec[b][tren+1] < c){
            tren++;
        }
        res += tren+1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec[x].push_back(i);
    }
    for(int i=1; i<=20; i++){
        for(int j=i+1; j<=20; j++){
            cost[i][j] = inv(i, j);
            cost[j][i] = 1LL*vec[i].size()*vec[j].size() - cost[i][j];
        }
    }
    n = 20;
    for(int i=1; i<(1<<n); i++){
        dp[i] = INF;
    }
    for(int i=0; i<(1<<n); i++){
        for(int j=1; j<=n; j++){
            if((1<<(j-1)) & i) continue;
            ll x = 0;
            for(int k=1; k<=n; k++){
                if((1<<(k-1)) & i){
                    x += cost[k][j];
                }
            }
            int r = i | (1<<(j-1));
            dp[r] = min(dp[r], dp[i] + x);
        }
    }
    cout << dp[(1<<n)-1];
    return 0;
}