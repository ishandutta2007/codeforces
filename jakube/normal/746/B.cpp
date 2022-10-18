#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int i;
    for (i = n-2; i >= 0; i-=2) {
        cout << s[i];
    }
    for (i = (i + 3) % 2; i < n; i+=2) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}