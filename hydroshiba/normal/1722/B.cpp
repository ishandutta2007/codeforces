#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n; cin >> n;

    string a, b;
    cin >> a >> b;

    for(char &c : a) if(c == 'G') c = 'B';
    for(char &c : b) if(c == 'G') c = 'B';

    cout << (a == b ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}