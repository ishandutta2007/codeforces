#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        long long n;
        cin >> n;
        long res = 0;
        while(n%2==0){
            n/=2;
            res ++;
        }
        while(n%3==0){
            n/=3;
            res += 2;
        }
        while(n%5==0){
            n/=5;
            res +=3;
        }
        if (n > 1) cout << -1;
        else cout << res;
        cout << "\n";
        
    }
}