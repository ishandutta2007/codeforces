#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int h[1000], a[1000];
map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i] >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += mp[h[i]];
    }
    cout << ans;
    return 0;
}