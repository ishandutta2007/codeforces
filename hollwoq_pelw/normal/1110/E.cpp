#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int c[n-1], d[n-1];
    for (int i = 0; i < n-1; i++){
        c[i] = a[i+1]-a[i];
        d[i] = b[i+1]-b[i];
    }
    sort(c,c+n-1);
    sort(d,d+n-1);
    for (int i = 0; i < n-1; i++){
        if (c[i] != d[i]) return cout << "NO", 0;
    }
    if (a[0] != b[0] && a[n-1] != b[n-1]) return cout << "NO", 0;
    return cout << "YES", 0;
}