#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string last = "";
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s != last) cnt++;
        last = s;
    }
    cout << cnt << endl;

    return 0;
}