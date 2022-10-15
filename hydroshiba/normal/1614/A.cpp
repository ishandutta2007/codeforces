#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, l, r, k;
    cin >> n >> l >> r >> k;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int pos = 0;
    while(pos < n && arr[pos] < l) ++pos;

    int ans = 0;
    while(pos < n && arr[pos] <= r && k >= arr[pos]){
        ++ans;
        k -= arr[pos];
        ++pos;
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}