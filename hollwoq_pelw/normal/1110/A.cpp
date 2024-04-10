#include <bits/stdc++.h>
using namespace std;
int main(){
    int b, k, a;
    cin >> b >> k;
    int p = 0;
    for (int i = k-1; i >= 0; i--){
        cin >> a;
        if (a%2 && (b%2 || i == 0)) p = 1-p;
    }
    string s = (p == 0) ? "even":"odd";
    cout << s;
    return 0;
}