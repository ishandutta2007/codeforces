#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; ++i){
        if(arr[i] == arr[i + 1]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}