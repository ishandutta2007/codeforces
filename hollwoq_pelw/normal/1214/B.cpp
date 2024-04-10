#include <bits/stdc++.h>
using namespace std;
int main(){
    int b,g,n,a = 0;
    cin >> b >> g >> n;
    for (int i = 0; i <= n; i++) a += (b >= i && g >= n-i);
    cout << a;
}