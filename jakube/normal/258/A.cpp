#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;
    
    string s;
    cin >> s;

    vector<char> v;
    bool b = true;
    for (char c : s) {
        if (c == '0' && b) {
            b = false;
        }
        else {
            v.push_back(c);
        }
    }

    if (b) v.pop_back();

    cout << string(v.begin(), v.end()) << endl;;

    return 0;
}