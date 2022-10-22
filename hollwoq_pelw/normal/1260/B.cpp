#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        n--;
        long c,s;
        cin >> c >> s;
        if ((c+s)%3==0 && c <= 2*s && s <= 2*c) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}