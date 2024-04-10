#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        cout << n * 3 << "\n"; 
        for(int i = 1, x; i <= n; i += 2){
            cin >> x >> x;
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 2 << " " << i << " " << i + 1 << "\n";
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 2 << " " << i << " " << i + 1 << "\n";
        }
    }
    return 0;
}