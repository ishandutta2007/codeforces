#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = n-1; i >= 0; i--) cin >> a[i];
    long long res = 0;
    int cur = INT_MAX;
    for (int i = 0; i < n; i++){
        cur = max(min(cur-1, a[i]), 0);
        res += cur;
    }
    cout << res;
    return 0;
}