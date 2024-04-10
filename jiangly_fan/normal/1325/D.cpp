#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL u, v;
    cin >> u >> v;
    if(u == 0 and v == 0) cout << 0;
    else if(u > v or (u - v) % 2) cout << -1;
    else if(u == v) cout << "1\n" << u;
    else{
        LL k = (v - u) / 2;
        if(k & u) cout << "3\n" << u << " " << k << " " << k;
        else cout << "2\n" << k << " " << (u | k);
    }
}