#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t=1, n;
    long long int w=0, x=0, y=0, z=0, ans=0;
    int a=0, b=0, c=0, d=0, e=0, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= 2*k-n-1; i++) cout << i << ' ';
        for(int i = 2*k-n; i <= k; i++) cout << 3*k-n-i << ' ';
        cout << '\n';
    }
}