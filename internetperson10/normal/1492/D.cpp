#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;
bool nums1[200001], nums2[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n, k;
    ll ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> m >> n >> k;
    if(m == 0 || n == 1) {
        if(k == 0) {
            cout << "Yes\n";
            for(int i = 0; i < n; i++) cout << 1;
            for(int i = 0; i < m; i++) cout << 0;
            cout << '\n';
            for(int i = 0; i < n; i++) cout << 1;
            for(int i = 0; i < m; i++) cout << 0;
        }
        else {
            cout << "No\n";
        }
        return 0;
    }
    if(m + n < k + 2) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    int x = n-2;
    cout << 1;
    for(int i = 1; i < m+n; i++) {
        if(i == 1) {
            cout << 1;
            continue;
        }
        if(i == k+1) {
            cout << 0;
            continue;
        }
        if(x) {
            x--;
            cout << 1;
        }
        else cout << 0;
    }
    x = n-2;
    cout << "\n1";
    for(int i = 1; i < m+n; i++) {
        if(i == k+1) {
            cout << 1;
            continue;
        }
        if(i == 1) {
            cout << 0;
            continue;
        }
        if(x) {
            x--;
            cout << 1;
        }
        else cout << 0;
    }
}