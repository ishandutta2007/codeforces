#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    int n;
    cin >> n;

    int sum = 0;

    vector<int> arr(n);
    for(int &i : arr) cin >> i, sum += i;

    int ans = inf;

    for(int k = 1; k <= n; ++k) if(sum % k == 0){
        int num = 0, val = sum / k, cur = 0, pos = 0;

        for(int i = 0; i < n; ++i){
            cur += arr[i];

            if(cur == val){
                num = max(num, i - pos + 1);
                pos = i + 1;
                cur = 0;
            }
        }

        if(cur == 0) ans = min(ans, num);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}