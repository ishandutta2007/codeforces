#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    lol a, b, c;
    cin >> a >> b >> c;

    if(a + b == c || b + c == a || a + c == b) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}