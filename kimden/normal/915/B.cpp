#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if(l == 1 && r == n){
        cout << 0 << endl;
        return 0;
    }
    if(l == 1){
        cout << 1 + abs(r - pos) << endl;
        return 0;
    }
    if(r == n){
        cout << 1 + abs(l - pos) << endl;
        return 0;
    }
    cout << 2 + (r - l) + min(abs(l - pos), abs(r - pos)) << endl;


}