#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n;
    cin >> n;

    int c = 1;
    --n;

    for(int i = 2; i != n - i; ++i){
        if(__gcd(i, n - i) == 1){
            cout << i << ' ' << n - i << ' ' << c << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}