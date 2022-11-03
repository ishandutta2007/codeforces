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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(n == 1){
        cout << 0 << endl;
    }else{
        cout << min(min(a, b) * (n - 1), min(a, b) + (n - 2) * c) << endl;
    }



}