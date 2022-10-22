#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[2*n+1];
    a[2*n] = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[n+i] = a[i];
    }
    int c = 0, m = 0;
    for (int i = 0; i < 2*n; i++){
        if (a[i]) c++;
        else {m = max(c, m); c = 0;}
    }
    cout << m;
    return 0;
}