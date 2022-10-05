#include <bits/stdc++.h>
using namespace std;

int a[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};

int main(){
    int n, ans = 0; cin >> n;
    if(n == 0){ puts("1"); return 0; }
    while(n){
        ans += a[n & 15];
        n /= 16;
    }
    cout << ans;
}