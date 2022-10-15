#include <bits/stdc++.h>
using namespace std;

void king_crimson(){
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 1;
    while(a % 2 == 0){
        a /= 2;
        ans *= 2;
    }
    while(b % 2 == 0){
        b /= 2;
        ans *= 2;
    }
    cout << (ans >= n ? "YES\n" : "NO\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int enemies;
    cin >> enemies;

    while(enemies--){
        king_crimson();
    }
}