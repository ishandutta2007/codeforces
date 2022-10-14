#include<bits/stdc++.h>

using namespace std;

int n;
string s, t;

int main () {
    cin >> n >> s;
    int ind = -1;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') ind = i;
    }
    if (ind == -1) {
        cout << "No";
        return 0;
    }
    t = "(";
    for (int i=0; i<n; i++) {
        if (i != ind) t += s[i];
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (t[i] == '(') cnt++; else cnt--;
        if (cnt < 0) {
            cout << "No";
            return 0;
        }
    }
    if (cnt == 0) cout << "Yes"; else cout << "No";
    return 0;
}