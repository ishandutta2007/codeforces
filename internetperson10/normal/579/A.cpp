#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, s=0;
    cin >> n;
    for(int a=0; a<32; a++) {
        if(n & (1<<a))
            s++;
    }
    cout << s;
}