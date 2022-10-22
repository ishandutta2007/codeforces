#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int i = 0;
        while(i * i < x) i++;
        i--;
        int g = (i * i + i + 1);
        if(x < g) cout << x - (i * i) << ' ' << i+1 << '\n';
        else cout << i+1 << ' ' << ((i+1) * (i+1)) - x + 1 << '\n';
    }
}