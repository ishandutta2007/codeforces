#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    char mn = 'z';
    for (int i=0; i<n; i++) {
        if (mn >= s[i]) cout << "Mike\n"; else cout << "Ann\n";
        mn = min(mn, s[i]);
    }
    return 0;
}