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
    int n, k;
    cin >> n >> k;
    int b = -1;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(k % a == 0 && b < a){
            b = a;
        }
    }
    cout << k / b << endl;



}