#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dp[500005];
ll niz[500005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, k, d;
    dp[0] = 1;
    cin >> n >> k >> d;
    for(int i=1; i<=n; i++) cin >> niz[i];
    sort(niz+1, niz+1+n);
    if(niz[k] > niz[1]+d){cout << "NO"; return 0;}
    dp[k] = 1;
    int l=1;
    ll ukup=1;
    for(int i=k+1; i<=n; i++){
        ukup += dp[i-k];
        if(niz[i] > niz[i-k+1]+d) continue;
        while(niz[i] > niz[l]+d){
            ukup -= dp[l-1];
            l++;
        }
        if(ukup > 0) dp[i] = 1;
    }
    if(dp[n]) cout << "YES";
    else cout << "NO";
    return 0;
}