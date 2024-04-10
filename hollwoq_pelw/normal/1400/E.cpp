#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5050], n;

int solve(int l, int r, int k = 0){
    if (l > r)
        return 0;
    
    int m = l;
    for (int i = l; i <= r; i++){
        if (a[i] < a[m]){
            m = i;
        }
    }
    return min(r - l + 1, a[m] - k + solve(l, m - 1, a[m]) + solve(m + 1, r, a[m]));
}

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    cout << solve(1, n);
}