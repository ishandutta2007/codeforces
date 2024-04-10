#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod;
inline int add(int a, int b){ a += b; if(a >= mod) a -= mod; return a;}
inline int mul(int a, int b){ return (a * 1ll * b) % mod;}
const int N = 1005;
int C[N][N], dp[N][N];
int col[N], row[N];
int ans(int n, int k){
    if(n == 0) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    int ret = 0;
    int f2 = k, f1 = 2 * n - 2 * k;
     if(f1 >= 2) ret = add(ret, mul(C[f1][2], ans(n - 1, k)));
    if(f1 >= 1 && f2 >= 1) ret = add(ret, mul(mul(f1, f2), ans(n - 1, k - 1)));
    if(f2 >= 2) ret = add(ret, mul(C[f2][2], ans(n - 1, k - 2)));
    return dp[n][k] = ret;
}
int main(){
    int n, m; string s;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> mod;
    for(int i = 0; i < N; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    for(int i = 0; i < m; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1') col[j]++, row[i]++;
        }
        if(row[i] != 2){cout << 0; return 0;}
    }
    int k =0;
    for(int j = 0; j < n; j++){
        if(col[j] > 2){ cout << 0; return 0;}
        col[j] = 2 - col[j];
        if(col[j] == 2) k++;
    }
    memset(dp, -1, sizeof dp);
    cout << ans(n - m, k) << endl;
}