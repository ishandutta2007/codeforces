#include<bits/stdc++.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;

int ham(int x, int y) {
    int dist = 0;
    for (int i = 0; i < 6; ++i) {
        int dx = x % 10;
        int dy = y % 10;
        dist += dx != dy;
        x /= 10;
        y /= 10;
    }
    return dist;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 6;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = ham(a[i], a[j]);
            dist = (dist - 1) / 2;
            ans = min(ans, dist);
        }
    }
    cout << ans << '\n';

    return 0;
}