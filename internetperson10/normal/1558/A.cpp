#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool taken[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int n = a+b;
        if(n%2) {
            int m = min(a, b);
            cout << 2 + 2*m << '\n';
            for(int i = n/2 - m; i <= (n+1)/2 + m; i++) cout << i << ' ';
            cout << '\n';
        }
        else {
            int m = min(a, b);
            cout << m+1 << '\n';
            for(int i = n/2 - m; i <= n/2 + m; i += 2) cout << i << ' ';
            cout << '\n';
        }
    }
}