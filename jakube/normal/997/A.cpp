#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    
    int cnt = 0;
    char last = '1';
    for (char c : s) {
        if (c != last && c == '0')
            cnt++;
        last = c;
    }

    if (cnt)
        cout << min((cnt - 1) * x + y, cnt * y) << '\n';
    else
        cout << 0 << '\n';
}