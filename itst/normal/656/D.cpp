#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , cnt = 0;
    cin >> n;
    while(n){
        if(n % 8 == 1)
            cnt++;
        n >>= 3;
    }
    cout << cnt;
    return 0;
}