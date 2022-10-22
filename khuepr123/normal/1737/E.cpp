/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int hf2[maxN];
int inv2;
int dp[maxN];

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    hf2[0] = 1;
    inv2 = pw(2, mod - 2);
    for1(i, 1, maxN - 1) hf2[i] = hf2[i - 1] * inv2 % mod;
    int o; cin >> o; while(o--){
        cin >> n;
        // find all interfering bitch
        int pool = 1;
        queue<int> q;
        for2(i, n, 1){
            while(!q.empty()){
                int node = q.front();
                int eat = (node + 1) / 2;
                if(node - eat >= i){
                    q.pop();
                    pool = (pool - dp[node]) % mod;
                    // cout << i << " " << node << " " << endl;
                }
                else break;
            }
            int eat = (i + 1) / 2;
            if(i == n){
                --eat; // cout << pool << " " << eat << endl;
            }
            dp[i] = pool * hf2[eat] % mod;
            q.push(i);
        }
        // dp[1] = 0;
        // dp[n] += hf2[n];
        for1(i, 1, n) cout << (dp[i] % mod + mod) % mod << endl;
    }
}