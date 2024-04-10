#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 88;
const int maxl = 19;
const int inf = INT_MAX / 2;

int num[maxn][maxl];

void solve(){
    int n;
    cin >> n;

    lol sum = 0;
    for(int i = 0; i < n; ++i){
        lol val;
        cin >> val;
        sum += val;
    }

    cout << bool(sum % n) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}