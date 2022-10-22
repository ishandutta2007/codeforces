#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    cout << x << " " << y << "\n"; int v = 0;
    if(y == m){
        for(int i = y - 1; i > 0; i--){
            cout << x << " " << i << "\n";
            v = 1;
        }
    }
    else{
        for(int i = 1; i < y; i++){
            cout << x << " " << i << "\n";
        }
        for(int i = y + 1; i <= m; i++){
            cout << x << " " << i << "\n";
        }
    }
    for(int j = 1; j <= n; j++){
        if(j == x){
            continue;
        }
        if(v){
            for(int i = 1; i <= m; i++){
                cout << j << " " << i << "\n";
            }
        }
        else{
            for(int i = m; i > 0; i--){
                cout << j << " " << i << "\n";
            }
        }
        v = 1 - v;
    }
}