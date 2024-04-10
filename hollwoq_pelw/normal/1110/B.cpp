#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int a[n], b[n-1];
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) b[i] = a[i+1]-a[i]-1;
    
    sort(b,b+n-1,greater<int>());
    
    //for (int i = 0; i < n-1; i++) cout << b[i] << ' ';
    
    long ans = a[n-1]-a[0]+1;
    for (int i = 0; i < k-1; i++) ans -= b[i];
    
    cout << ans;
    return 0;
}