#include<bits/stdc++.h>

using namespace std;

int n, k, len;
string s, t;

int main () {
    cin >> n >> k;
    int br = (n - k) / 2;
    for (int i=0; i<br; i++) {
        t += '0';
    }
    t += '1';
    while (len < n) {
        s += t;
        len += br+1;
    }
    for (int i=0; i<n; i++) {
        cout << s[i];
    }
    return 0;
}