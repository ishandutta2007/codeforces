#include <bits/stdc++.h>
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    vector<lol> arr(7);
    for(lol &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[6] - arr[0] - arr[1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}