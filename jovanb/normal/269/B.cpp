#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[10009];
ll dp[10009];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    double kur;
    for(int i=1; i<=n; i++){
        cin >> niz[i] >> kur;
    }
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(niz[i] >= niz[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    ll maxi = 0;
    for(int i=1; i<=n; i++) maxi = max(maxi, dp[i]);
    cout << n-maxi;
    return 0;
}