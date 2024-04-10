#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c=1;
    cin >> n;
    for(int a=1; a>-1; a++) {
        int k = a, t = 0;
        c = 0;
        while(k) {
            if(k & (1 << t)) {
                c+=pow(10, t);
                k-=(1<<t);
                //cout << c << ' ';
            }
            t++;
        }
        if(c>n) {
            cout << a-1;
            break;
        }
        //cout << c << ' ' << a << '\n';
    }
}