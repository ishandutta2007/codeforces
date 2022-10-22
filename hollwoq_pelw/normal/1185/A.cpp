#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3],d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a,a+3);
    cout << max(d-a[1]+a[0], 0) + max(d-a[2]+a[1], 0);
    return 0;
}