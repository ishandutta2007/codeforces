#include <bits/stdc++.h>
using namespace std;

short pen[4005][4005];
int C[4005][4005];
int dp[805][4005];

const int INF = 1000000000;

void compute(int nivo, int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = (l+r)/2;
    int mink = optl-1;
    int g = INF;
    for(int i=optl; i<=optr; i++){
        int x = dp[nivo-1][i-1] + C[mid][i];
        if(g > x){
            g = x;
            mink = i;
        }
    }
    dp[nivo][mid] = g;
    if(l == r) return;
    compute(nivo, l, mid-1, optl, mink);
    compute(nivo, mid+1, r, mink, optr);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> pen[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        int sad = 0;
        for(int j=i-1; j>=1; j--){
            sad += pen[i][j];
            C[i][j] = C[i-1][j] + sad;
        }
    }
    for(int i=1; i<=n; i++){
        dp[0][i] = INF;
    }
    for(int i=1; i<=k; i++){
        dp[i][0] = INF;
    }
    for(int i=1; i<=n; i++){
        dp[1][i] = C[i][1];
    }
    for(int i=2; i<=k; i++){
        compute(i, 1, n, 1, n);
    }
    cout << dp[k][n];
    return 0;
}