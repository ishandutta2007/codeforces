#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll MOD = 1111169;
vector<ll> nums;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 2; i <= n; i++) cout << i << ' ';
        cout << 1 << '\n';
    }
}