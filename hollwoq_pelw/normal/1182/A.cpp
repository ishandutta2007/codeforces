#include <bits/stdc++.h>
using namespace std;
long long p(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;
    return p(n/2)*p(n/2)*p(n%2);
}
int main(){
    int n;
    cin >> n;
    if (n%2){
        cout << 0;
        return 0;
    }
    cout << p(n/2);
    return 0;
}