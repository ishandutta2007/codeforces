#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int s = 0;
    while(n > 9) {
        s = 0;
        while(n) {
            s += n%10;
            n /= 10;
        }
        n = s;
    }
    cout << n << '\n';
}