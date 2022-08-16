#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
const int N = 105, K = 21;
int dp[K + 1][2 * K + 2][N];
vector<int> con[N];
int k, n, u, v;
void add(int & x, int y){
    x += y;
    if(x >= mod) x -= mod;
}
void dfs(int s, int p){
    int arr1[N + 1][K + 1][2 * K + 2];
    int arr2[N + 1][K + 1][2 * K + 2];
    memset(arr1, 0, sizeof arr1);
    memset(arr2, 0, sizeof arr2);
    arr1[0][1][2 * K] = 1;
    arr2[0][0][1] = 1;
    int ind = 0;
    for(int v : con[s]){
        if(v != p){
            dfs(v, s);
            ++ind;
            for(int p = 0; p <= k; p++){
                for(int q = 0; q <= 2 * K; q++){
                    for(int x = 0; x <= k; x++){
                        for(int y = 0; y <= 2 * K; y++){
                            int mx1 = max(p + 1, x);
                            int mn1 = min(K << 1, min(q + 1, y));
                            if(mx1 + mn1 - 2 <= k){
                                mx1 = 0;
                            }
                            if(mx1 <= k) add(arr1[ind][mx1][mn1], mul(arr1[ind - 1][x][y], dp[p][q][v]));
                        }
                    }
                }
            }
            for(int x = 0; x <= k; x++){
                for(int p = 0; p <= k; p++){
                    for(int q = 0; q <= 2 * K; q++){
                        int mx = max(x, p + 1);
                        if(mx <= k + 1) mx = 0;
                        if(mx > k) continue;
                        add(arr2[ind][mx][1], mul(dp[p][q][v], arr2[ind - 1][x][1]));
                    }
                }
            }
        }
    }
    for(int p = 0; p <= k; p++)
        for(int q = 0; q <= 2 * K; q++){
            add(dp[p][q][s], arr1[ind][p][q]);
            add(dp[p][q][s], arr2[ind][p][q]);
        }
}
int main(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        con[u].push_back(v);
        con[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int q = 1; q <= 2 * k + 1; q++){
        add(ans, dp[0][q][1]);
    }
    cout << ans;
}