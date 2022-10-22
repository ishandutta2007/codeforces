#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x=0,y=0;
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++){
        if (i < n/2) x += a[i];
        else y += a[i];
    }
    cout << x*x+y*y;
    return 0;
}