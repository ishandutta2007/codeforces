#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int c = 0;
    for (int i = 1; i < n; i++){
        if (a[i]+a[i-1] < 5) c += a[i]+a[i-1];
        else {cout << "Infinite"; return 0;}
    }
    for (int i = 2; i < n; i++) if (a[i] == 2 && a[i-2] == 3) c --;
    cout << "Finite\n" << c;
}