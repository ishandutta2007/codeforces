#include<bits/stdc++.h>
using namespace std;
int main() { 
    int n, a, b, res = 0;
    cin >> n;
    while (n){
        n--;
        cin >> a >> b;
        res += (b-a) > 1;
    }
    cout << res;
    return 0;
}