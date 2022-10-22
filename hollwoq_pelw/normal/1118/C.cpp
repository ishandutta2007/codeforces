#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> c;

int main(){
    cin >> n;
    int a[n][n], s;
    for (int i = 0; i < n*n; i++){
        cin >> s;
        c[s] ++;
    }
    // build 4 corner
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            int x = -1;
            for(auto [p,v]:c){
                if (v >= 4) {c[p] -= 4; x = p; break;}
            }
            if (x == -1) return cout << "NO", 0;
            a[i][j] = a[n-i-1][j] = a[n-i-1][n-j-1] = a[i][n-j-1] = x;
        }
    }
    // build 2 cross
    if (n%2){
        for (int i = 0; i < n/2; i++){
            int x = -1;
            for(auto [p,v]:c){
                if (v >= 2) {c[p] -= 2; x = p; break;}
            }
            if (x == -1) return cout << "NO", 0;
            a[i][n/2] = a[n-i-1][n/2] = x;
        }
        for (int j = 0; j < n/2; j++){
            int x = -1;
            for(auto [p,v]:c){
                if (v >= 2) {c[p] -= 2; x = p; break;}
            }
            if (x == -1) return cout << "NO", 0;
            a[n/2][j] = a[n/2][n-j-1] = x;
        }
        for (auto [p,v]:c){
            //cout << p << ' ' << v;
            if(v > 0) {a[n/2][n/2] = p; break;}
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    
    
    return 0;
}