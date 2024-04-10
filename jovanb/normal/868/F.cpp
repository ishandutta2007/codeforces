#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;
const ll INF = 1000000000000000000LL;

ll dp[2][N+5];
int a[N+5];

int L, R;
int cnt[N+5];

ll sum;

void dodaj(int x, int k){
    if(k == 1) sum += cnt[x], cnt[x]++;
    else cnt[x]--, sum -= cnt[x];
}

void fix(int l, int r){
    while(R < r) R++, dodaj(a[R], 1);
    while(L > l) L--, dodaj(a[L], 1);
    while(R > r) dodaj(a[R], -1), R--;
    while(L < l) dodaj(a[L], -1), L++;
}

void solve(int l, int r, int tl, int tr){
    if(l > r) return;
    int mid = (l+r)/2;
    int opt = tl;
    fix(opt, mid);
    ll opr = dp[0][tl-1] + sum;
    for(int j=tl+1; j<=min(mid, tr); j++){
        fix(j, mid);
        if(dp[0][j-1] + sum <= opr) opt = j, opr = dp[0][j-1] + sum;
    }
    dp[1][mid] = opr;
    solve(l, mid-1, tl, opt);
    solve(mid+1, r, opt, tr);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        dp[1][i] = INF;
        cin >> a[i];
    }
    L = R = 1;
    dodaj(a[1], 1);
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++) dp[0][j] = dp[1][j];
        for(int j=0; j<=n; j++) dp[1][j] = INF;
        solve(1, n, 1, n);
    }
    cout << dp[1][n] << "\n";
    return 0;
}