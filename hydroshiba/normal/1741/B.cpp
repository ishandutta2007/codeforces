#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

char comp(string a, string b){
    if(a == b) return '=';

    if(a[0] != b[0]){
        if(a[0] == 'S') return '<';
        if(b[0] == 'S') return '>';

        if(a[0] == 'M') return '<';
        if(b[0] == 'M') return '>';
    }

    if(a.size() < b.size()) return (a[0] == 'L' ? '<' : '>');
    else return (a[0] == 'L' ? '>' : '<');
}

void solve(){
    int n;
    cin >> n;

    if(n == 3){
        cout << "-1\n";
        return;
    }

    int mid = n / 2 + (n & 1);

    for(int i = n; i > mid; --i) cout << i << ' ';
    for(int i = 1; i <= mid; ++i) cout << i << ' ';

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}