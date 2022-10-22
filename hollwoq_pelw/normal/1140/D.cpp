#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    long long res = 0;
    for (int i = 2; i < t; i++){
        res += i*(i+1);
    }
    cout << res;
    return 0;
}