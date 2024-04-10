#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int &i : arr) cin >> i, --i;

    string s(m, 'B');
    --m;

    for(int i : arr){
        if(s[min(i, m - i)] == 'A') s[max(i, m - i)] = 'A';
        s[min(i, m - i)] = 'A';
    }

    cout << s << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}