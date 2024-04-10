#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >= 0){cout << n; return 0;}
    cout << max(n/10, 10*(n/100) + (n%10));
}