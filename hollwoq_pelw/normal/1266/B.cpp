#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        n--;
        long long x;
        cin >> x;
        int t = x%14;
        if (t>0 && t<7 && x > 14) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}