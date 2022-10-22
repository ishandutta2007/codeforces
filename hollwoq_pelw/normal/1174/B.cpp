#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int c[2] = {0,0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]%2] ++;
    }
    if (c[0] && c[1]) sort(a,a+n);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}