#define x firsts
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    char a[8][8];

    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j) cin >> a[i][j];

    for(int i = 0; i < 8; ++i){
        bool ok = (a[i][0] != '.');
        for(int j = 0; j < 8; ++j) ok = ok && (a[i][j] == 'R');

        if(ok){
            cout << 'R' << '\n';
            return;
        }
    }

    for(int j = 0; j < 8; ++j){
        bool ok = (a[0][j] != '.');
        for(int i = 0; i < 8; ++i) ok = ok && (a[i][j] == 'B');

        if(ok){
            cout << 'B' << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}