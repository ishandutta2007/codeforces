#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dob[1005][1005];
int dp[1005];
int a[1005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dob[i][i] = a[i];
        a[i] += a[i-1];
    }
    for(int sz=2; sz<=n; sz++){
        for(int l=1; l+sz-1<=n; l++){
            int r = l+sz-1;
            for(int k=l; k<r; k++){
                if(dob[l][k] == dob[k+1][r] && dob[l][k]) dob[l][r] = dob[l][k] + 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        dp[i] = i;
        for(int j=0; j<i; j++){
            if(dob[j+1][i]) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}