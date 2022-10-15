#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i, --i;

    vector<int> last(n, -1), cur(n), ans(n);

    for(int i = 0; i < n; ++i){
        if(last[arr[i]] == -1){
            last[arr[i]] = i;
            cur[arr[i]] = 1;
            continue;
        }

        int dist = i - last[arr[i]] - 1;
        if(dist % 2 == 0){
            ++cur[arr[i]];
            last[arr[i]] = i;
        }
    }

    for(int i = 0; i < n; ++i) ans[i] = max(ans[i], cur[i]);
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}