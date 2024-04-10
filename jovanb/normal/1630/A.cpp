#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k == n - 1){
            if(n == 4){
                cout << "-1\n";
                continue;
            }
            cout << 0 << " " << 2 << "\n";
            cout << 1 << " " << n - 3 << "\n";
            cout << n - 2 << " " << n - 1 << "\n";
            for(int i=3; 2*i<n; i++) cout << i << " " << n - 1 - i << "\n";
            continue;
        }
        if(k == 0){
            for(int i=0; 2*i<n; i++) cout << i << " " << n - 1 - i << "\n";
            continue;
        }
        cout << 0 << " " << n - 1 - k << "\n";
        cout << k << " " << n - 1 << "\n";
        for(int i=1; 2*i<n; i++){
            if(i == n - 1 - k || i == k) continue;
            else cout << i << " " << n - 1 - i << "\n";
        }
    }
    return 0;
}