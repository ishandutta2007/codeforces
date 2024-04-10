#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    long long c = 0;
    for (int i = 0; i < n/2; i++){
        c+=1ll*pow(a[i]+a[n-i-1], 2);
    }
    cout << c;
    return 0;
}