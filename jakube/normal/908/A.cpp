#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt = 0;
    string t = "aeiou13579";
    for (char c : s) {
        if (t.find(c) != string::npos)
            cnt++;
    }
    cout << cnt << '\n';
    
}