#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll v[100001], u[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    v[0] = u[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i < n; i++) {
        u[i] = max(0LL, v[i+1] - v[i]);
        v[i] = max(0LL, v[i] - v[i+1]);
    }
    for(int i = 1; i < n; i++) {
        v[i] += v[i-1];
        u[i] += u[i-1];
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(x < y) cout << v[y-1] - v[x-1] << '\n';
        else cout << u[x-1] - u[y-1] << '\n';
    }
}