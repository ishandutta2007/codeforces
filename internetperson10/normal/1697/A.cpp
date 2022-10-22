#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int sum = 0;
        while(n--) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << max(0, sum - m) << '\n';
    }
}