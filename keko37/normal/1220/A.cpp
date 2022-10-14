#include<bits/stdc++.h>

using namespace std;

int n, a, b;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i] == 'n') a++;
    }
    b = (n - 3*a) / 4;
    for (int i=0; i<a; i++) cout << 1 << " ";
    for (int i=0; i<b; i++) cout << 0 << " ";
    return 0;
}