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
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << comp(a, b) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}