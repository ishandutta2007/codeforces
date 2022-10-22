#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[2*n];
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a,a+2*n);
    int c = 0;
    for (int i = 0; i < n; i++){
        c += a[i];
        c -= a[i+n];
    }
    if (c != 0){
        for (int i = 0; i < 2*n; i++) cout << a[i] << ' ';
    }else{
        cout << -1;
    }
    return 0;
}