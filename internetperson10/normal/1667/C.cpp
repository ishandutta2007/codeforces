#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = (2 * n + 1) / 3;
    cout << x << '\n';
    if(x % 2 == 0) {
        cout << n << ' ' << n << '\n';
        n--;
        x--;
    }
    for(int i = 1; i <= (x+1)/2; i++) {
        cout << i << ' ' << ((x+1)/2 + 1 - i) << '\n';
    }
    for(int i = 1; i <= (x)/2; i++) {
        cout << n+1-i << ' ' << (n+1-(x/2 + 1 - i)) << '\n';
    }
}