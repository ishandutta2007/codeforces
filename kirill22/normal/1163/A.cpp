#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    if(m == 0){
        cout << 1;
        return 0;
    }
    int ans = 0 ;
    if(n % 2 == 0){
        if(m <= n / 2){
            cout << m;
        }
        else{
            cout << n - m;
        }
    }
    else{
        if(m <= n / 2){
            cout << m;
        }
        else{
            cout << n - m;
        }
    }
}