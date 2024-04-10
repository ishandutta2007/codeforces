// Hydro submission #622b3074724815af336d419f@1646997621822
#include<bits/stdc++.h>

using namespace std;


void slove(){
    int n; cin >> n;
    int k = sqrt(n);
    if(k * k == n){
        cout << k * 4 << '\n';
    } else {
        if(n - k * k > k){
            cout << k * 4 + 4 << '\n';
        }
        else cout << k * 4 + 2 << '\n';
    }


}


int main(){ 
    ios_base::sync_with_stdio(0), cin.tie(0);
    slove();
    
}