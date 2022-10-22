#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,r;
    cin >> n >> m >> r;
    int mn = 0, mx = 0, x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (i == 0 || x < mn) mn = x;
    }
    for (int i = 0; i < m; i++){
        cin >> x;
        if (i == 0 || x > mx) mx = x;
    }
    if (mn >= mx) cout << r;
    else cout << (r/mn)*mx+r%mn;
    return 0;
}