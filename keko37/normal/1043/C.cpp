#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main () {
    cin >> s;
    n = s.size();
    for (int i=0; i<n-1; i++) {
        cout << (s[i] != s[i+1]) << " ";
    }
    cout << (s[n-1] == 'a');
    return 0;
}