#include <bits/stdc++.h>
using namespace std;
int64_t n, k, a[200002], x, y, z;
int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i]; 
    sort(a, a + n);
    for (int i = 0; i <= n-k; i++) 
        if (a[i] == a[i+k-1]) return cout << 0, 0;
    for (int i = 0; i < n; i++){
        if (i < k){
            x += a[k-1] - a[i];
            y += a[n-i-1] - a[n-k];
        }else{
            x -= a[i] == a[k-1];
            y -= a[n-i-1] == a[n-k];
        }
        z += abs(a[(n-1)/2] + (i >= k) - a[i]);
    }
    cout << min({x, y, z});
}