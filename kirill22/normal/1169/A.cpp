#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, a, b ,x ,y;
    cin >> n >> a >> x >> b >> y;
    while(a != x && b != y){
        if(a == b){
            cout << "YES";
            return 0;
        }
        a++;
        b--;
        if(a == n + 1){
            a = 1;
        }
        if(b == 0){
            b = n;
        }
        if(a == b){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}