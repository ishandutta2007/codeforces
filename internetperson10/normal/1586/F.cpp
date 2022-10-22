#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> col;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int g = 1, ans = 0;
    while(g < n) {
        g *= k;
        ans++;
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int gee = 0;
            int x = i, y = j;
            while(x != y) {
                gee++;
                x /= k;
                y /= k;
            }
            cout << gee << ' ';
        }
    }
}