#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = -1, b = -1;
    string vow = "aioue";
    for (int i = 5; i <= sqrt(n); i++){
        if (n%i == 0){
            a = i;
            b = n/i;
        }
    }
    if (a == -1) {cout << -1; return 0;}
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            cout << vow[(i+j)%5];
        }
    }
    return 0;
}