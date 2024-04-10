
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int n, k;
 
int kol[1100];
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ++kol[x];
    }
    int hv = (n+1)/2;
    int koll = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++){
        int mn = min(hv, kol[i]/2);
        hv -= mn;
        ans += mn*2;
        kol[i] -= mn*2;
        if (kol[i])
            ++koll;
    }
    ans += min(hv, koll);
    cout << ans;
 
}