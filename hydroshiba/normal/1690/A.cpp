#include "bits/stdc++.h"
using namespace std;

void solve(){
    int a, b = 0, c = 0;
    cin >> a;

    a -= 3;
    b = 2;
    c = 1;

    int aa, bb, cc;
    bool turn = false;

    while(a > b && a > c){
        aa = a;
        bb = b;
        cc = c;

        --a;
        if(!turn) ++b;
        else ++c;

        turn = !turn;
    }

    cout << bb << ' ' << aa << ' ' << cc << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}