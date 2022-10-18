#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt1 = 0;
    for (char c : s)
        cnt1 += c == '1';
    
    string res;
    char last = '0';
    int cnt = 0;
    for (char c : s + '3') {
        if (c == '1')
            continue;
        if (c == last)
            cnt++;
        else {
            res += string(cnt, last);
            res += string(cnt1, '1');
            cnt1 = 0;
            last = c;
            cnt = 1;
        }
    }
    cout << res << '\n';
}