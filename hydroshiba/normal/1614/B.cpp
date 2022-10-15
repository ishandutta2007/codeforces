#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    vector<ii> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x;
        arr[i].y = i;
    }

    sort(arr.begin(), arr.end(), greater<ii>());

    lol ans = 0;
    int pos = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0) ++pos;


        ans += 2LL * (lol)pos * (lol)arr[i].x;
        arr[i].x = (i % 2 == 0 ? pos : -pos);
        swap(arr[i].x, arr[i].y);
    }

    cout << ans << '\n' << "0 ";
    sort(arr.begin(), arr.end());
    for(ii i : arr) cout << i.y << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}