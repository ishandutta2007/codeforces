#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int door[3], k;
    cin >> k >> door[0] >> door[1] >> door[2];

    vector<bool> open(3);
    while(k){
        open[k - 1] = true;
        k = door[k - 1];
    }

    for(bool i : open) if(!i){
        cout << "NO\n";
        return;
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