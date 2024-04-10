#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 99999;
    for(int i = 0; i < 102; i++){
        ans = min(ans, abs(a - i) + abs(b - i) + abs(c - i));
    }
    cout << ans;
    return 0;
}