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
    int cnt = 1;
    for(ii &i : arr) cin >> i.x, i.y = cnt++;

    sort(arr.begin(), arr.end());

    cout << (*arr.rbegin()).y << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}