#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<lol> arr(n);
    lol num[2]; num[0] = 0; num[1] = 0;

    for(lol &i : arr) cin >> i, ++num[i & 1];

    lol sum = accumulate(arr.begin(), arr.end(), 0LL);

    while(q--){
        lol tt, val;
        cin >> tt >> val;

        sum += val * num[tt];

        if(tt != (val & 1) && tt == 0){
            int temp = num[0];
            num[0] -= temp;
            num[1] += temp;
        }
        else if(tt == (val & 1) && tt == 1){
            int temp = num[1];
            num[1] -= temp;
            num[0] += temp;
        }

        cout << sum << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}