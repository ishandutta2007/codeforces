#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const int mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2; bool chk[maxN];
int tmp[maxN]; int col[maxN]; int row[maxN];
int dp[maxN]; int mx; int l;

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m; mx = 0; int max_ans[maxN];
    tmp[0] = 0; col[0] = 1; row[0] = 1; dp[0] = 0;
    for(int i = 1; i <= m; i++){
        cin >> tmp[i] >> col[i] >> row[i]; dp[i] = 0 - mod;
        for(int j = max(0, i - 1005); j < i; j++){
            if(tmp[i] - tmp[j] >= (abs(col[i] - col[j]) + abs(row[i] - row[j]))){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (i > 2*n) dp[i] = max(dp[i], 1 + max_ans[i-2*n]);
        max_ans[i] = max(dp[i], max_ans[i-1]);
        
    }
    for(int i = 0; i <= m; i++){
        mx = max(mx, dp[i]);
    }
    mx = max(dp[1], mx); cout << mx;
}