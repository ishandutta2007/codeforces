#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 1 && b == 1){
        cout << "YES\n" << n << " 0" << endl;
        return 0;
    }
    bool bb = false;
    if(a < b){
        bb = true;
        swap(a, b);
    }
    ll i, j;
    for(i = 0, j = n; i <= n; i += a, j -= a){
        if(j % b == 0){
            if(bb){
                cout << "YES\n" << j / b << " " << i / a << endl;
            }else{
                cout << "YES\n" << i / a << " " << j / b << endl;
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}