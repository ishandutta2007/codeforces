#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<bool> possible(27, false);
    for (char c : s)
        possible[c - 'a'] = true;

    int res = 0;
    for (int i = 0; i < 26 && k; i++) {
        if (possible[i]) {
            res += i + 1;
            possible[i+1] = false;
            k--;
        }
    }
    cout << (k ? -1 : res) << endl;
}