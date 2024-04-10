#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    for (int i = a; ; i++){
        int x = i, s = 0;
        while(x){
            s += x%10;
            x/=10;
        }
        if (s%4 == 0){
            cout << i; 
            break;
        }
    }
    return 0;
}