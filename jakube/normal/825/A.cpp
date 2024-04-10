#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s) {
        if (c == '0') {
            cout << cnt;
            cnt = 0;
        }
        else
            cnt++;
    }
    cout << cnt;
    cout << endl;
}