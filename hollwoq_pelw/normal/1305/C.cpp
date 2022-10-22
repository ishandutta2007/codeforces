#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    if (n > m) return cout << 0, 0;
    long res = 1;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            res = res*(abs(a[i]-a[j])%m)%m;
        }
    }
    cout << res;
    return 0;
}