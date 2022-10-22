#include <bits/stdc++.h>
using namespace std;
bool ispri(int n){
    for (int i = 2; i <= sqrt(n); i++) if (n%i==0) return 0;
    return (n > 1);
}
int main(){
    int n;
    cin >> n;
    int c[2] = {0, 0}, x;
    for (int i = 0; i < n; i++) {cin >> x; c[x-1]++;}
    int cur = 0;
    //cout << ispri(4);
    while(c[1]){
        cur ++;
        if (c[0] && ispri(cur)) {cout << 1 << ' '; c[0] --;}
        else {cur ++; cout << 2 << ' '; c[1] --;}
        
    }while(c[0]--){
        cout << 1 << ' ';
    }
    return 0;
}